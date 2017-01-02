<?php
	// ----------------
	// PacketGenerator
	// Maxime BACONNAIS
	// ----------------
	
	function recurs_search($data)
	{
		$tab = [];
		foreach ($data as $arg)
		{
			if (strpos($arg['type'], 'std::vector') === 0)
			{
				array_push($tab, '"'.vector2name($arg['type']).'.hpp"');
				$tab = array_merge($tab, recurs_search($arg['vector']));
			}
		}
		return ($tab);
	}
	
	function createHH($class, $dir)
	{
		$name = 'Packet'.ucfirst($class['name']);
		
		$includes = array('<stdint.h>');
		
		foreach ($class['arguments'] as $arg)
		{
			if (strpos($arg['type'], 'std::vector') === 0 && !in_array('<vector>', $includes))
				array_push($includes, '<vector>');
			
			if (strpos($arg['type'], 'std::string') === 0 && !in_array('<string>', $includes))
				array_push($includes, '<string>');
		}
		
		array_push($includes, '"APacket.hh"');
		
		foreach ($class['arguments'] as $arg)
		{
			if (strpos($arg['type'], 'std::vector') === 0)
			{
				array_push($includes, '"'.vector2name($arg['type']).'.hpp"');
			}
		}
		
		$macro = strtoupper('Packet'.$class['name']);
		
		// ----------------------- //
		
		// Ifndef macro
		$dataH = "#ifndef __".$macro."_HH__\n#define __".$macro."_HH__\n\n";

		// Includes
		foreach ($includes as $include)
			$dataH .= "#include ".$include."\n";
			
		// Namespace
		$dataH .= "\nnamespace Packet {\n\n";

		// Class
		$dataH .= "\tclass ".$name." : public APacket {\n";
		
		// Public part
		$dataH .= "\n\tpublic:\n";
		
		$args = arguments($class['arguments']);
		
		// Constructors and destructors
    	$dataH .= "\t\t".$name."(".$args.");\n\t\t".$name."(const uint8_t *data);\n\t\t~".$name."();\n\n";
    
		// Getters
		foreach ($class['arguments'] as $arg)
		{
			if (strpos($arg['type'], '[') !== false && strpos($arg['type'], ']') !== false)
				$dataH .= "\t\t".explode('[', $arg['type'])[0]." *get".ucfirst($arg['name'])."();\n";
			else
				$dataH .= "\t\t".$arg['type']." get".ucfirst($arg['name'])."() const;\n";
		}
		
		// isTcp()
		$dataH .= "\t\tbool isTcp() const;\n";
		
		// isUdp()
		$dataH .= "\t\tbool isUdp() const;\n";
		
			
		// Protected part
		$dataH .= "\n\tprivate:\n";
			
		// Vars
		foreach ($class['arguments'] as $arg)
		{
			if (strpos($arg['type'], '[') !== false && strpos($arg['type'], ']') !== false)
				$dataH .= "\t\t".explode('[', $arg['type'])[0]." _".$arg['name']."[".explode('[', $arg['type'])[1].";\n";
			else
				$dataH .= "\t\t".$arg['type']." _".$arg['name'].";\n";
		}
		
		// Eend class
		$dataH .= "\t};";
		
		// Eend namespace
		$dataH .= "\n};";

		// endif
		$dataH .= "\n\n#endif";
		
		
		$header = "//\n// This file was auto-generated, please do not edit it !\n//\n\n";
		file_put_contents($dir.$name.'.hh', $header.$dataH);
	}

	function create_serializer_code($args, $depth, $path)
	{
		$alpha = "ijklmnopqrstuvwxyzabcdefgh";
		$alpha = str_split($alpha);
		
		// Add to parser
		$data = '';
		
		$indent = str_repeat("\t", $depth + 1);
		
		foreach ($args as $arg)
		{
			if ($depth <= 0)
				$access = "_".$arg['name'];
			else
				$access = $path."->get".ucfirst($arg['name'])."()";
			
			$data .= "\n";
			
			if ($arg['type'] == 'std::string')
				$data .= $indent."ps.add((uint16_t)".$access.".size());\n".$indent."ps.add(".$access.");\n".$indent."dataPacketSize += 2 + (uint32_t)".$access.".size();\n";
			if ($arg['type'] == 'uint8_t')
				$data .= $indent."ps.add(".$access.");\n".$indent."dataPacketSize += 1;\n";
			if ($arg['type'] == 'bool')
				$data .= $indent."ps.add((uint8_t) ".$access.");\n".$indent."dataPacketSize += 1;\n";
			if ($arg['type'] == 'uint16_t')
				$data .= $indent."ps.add(".$access.");\n".$indent."dataPacketSize += 2;\n";
			if ($arg['type'] == 'uint32_t')
				$data .= $indent."ps.add(".$access.");\n".$indent."dataPacketSize += 4;\n";
			if (strpos($arg['type'], '[') !== false && strpos($arg['type'], ']') !== false && strpos($arg['type'], 'uint8_t') !== false)
			{
				$nb = explode(']', explode('[', $arg['type'])[1])[0];
				for ($x = 0; $x < $nb; $x++)
					$data .= $indent."ps.add(".$access."[".$x."]);\n";
				$data .= $indent."dataPacketSize += ".$x.";\n";
			}
			if ($arg['type'] == 'IPacket::PacketType')
				$data .= $indent."ps.add((uint8_t)".$access.");\n".$indent."dataPacketSize += 1;\n";
			if (strpos($arg['type'], 'std::vector') === 0)
			{
				$data .= $indent."ps.add((uint16_t)".$access.".size());\n".$indent."dataPacketSize += 2;\n".$indent."for (uint64_t ".$alpha[$depth]." = 0; ".$alpha[$depth]." < ".$access.".size(); ".$alpha[$depth]."++)\n".$indent."{";
				$data .= create_serializer_code($arg['vector'], $depth + 1, $access.'['.$alpha[$depth].']');
				$data .= $indent."}\n";
			}
		}
		return ($data);
	}
	
	function create_deserializer_code($args, $depth, $path)
	{
		$alpha = "ijklmnopqrstuvwxyzabcdefgh";
		$alpha = str_split($alpha);
		
		// Add to parser
		$data = '';
		
		$indent = str_repeat("\t", $depth + 1);
		
		foreach ($args as $arg)
		{
			if ($depth <= 0)
			{
				$access = "_".$arg['name'].' = ';
				$accesstab = "_".$arg['name'];
				$eaccess = "";
				$gaccess = "_".$arg['name'];
			}
			else
			{
				$access = $path."->set".ucfirst($arg['name'])."(";
				$accesstab = $path."->get".ucfirst($arg['name'])."()";
				$eaccess = ")";
				$gaccess = $path."->get".ucfirst($arg['name'])."()";
			}
			
			$data .= "\n";
			
			if ($arg['type'] == 'std::string')
				$data .= $indent.$access."pd.getString(posInPacket + 2, pd.get16(posInPacket))".$eaccess.";\n".$indent."posInPacket += 2 + (uint32_t)pd.get16(posInPacket);\n";
			if ($arg['type'] == 'uint8_t')
				$data .= $indent.$access."pd.get8(posInPacket)".$eaccess.";\n".$indent."posInPacket += 1;\n";
			if ($arg['type'] == 'bool')
				$data .= $indent.$access."((pd.get8(posInPacket) > 0) ? 1 : 0)".$eaccess.";\n".$indent."posInPacket += 1;\n";
			if ($arg['type'] == 'uint16_t')
				$data .= $indent.$access."pd.get16(posInPacket)".$eaccess.";\n".$indent."posInPacket += 2;\n";
			if ($arg['type'] == 'uint32_t')
				$data .= $indent.$access."pd.get32(posInPacket)".$eaccess.";\n".$indent."posInPacket += 4;\n";
			if ($arg['type'] == 'uint8_t[4]')
			{
				$nb = explode(']', explode('[', $arg['type'])[1])[0];
				for ($x = 0; $x < $nb; $x++)
					$data .= $indent.$accesstab."[".$x."] = pd.get8(posInPacket);\n".$indent."posInPacket += 1;\n";
			}
			if ($arg['type'] == 'IPacket::PacketType')
				$data .= $indent.$access."(IPacket::PacketType)pd.get8(posInPacket)".$eaccess.";\n".$indent."posInPacket += 1;\n";
			if (strpos($arg['type'], 'std::vector') === 0)
			{
				$vectorType = explode('<', $arg['type'])[1];
				$vectorType = explode('>', $vectorType)[0];
				$vectorType = str_replace('*', '', $vectorType);
				$vectorType = trim($vectorType);
				
				$data .= $indent."uint64_t ".$arg['name']."Length = pd.get16(posInPacket);\n".$indent."posInPacket += 2;\n";
				
				$data .= $indent."for (uint64_t ".$alpha[$depth]." = 0; ".$alpha[$depth]." < ".$arg['name']."Length; ".$alpha[$depth]."++)\n".$indent."{\n";
				
				$data .= $indent."\t".$vectorType." *".$arg['name']."Temp = new ".$vectorType."();\n";
				
				$data .= create_deserializer_code($arg['vector'], $depth + 1, $arg['name']."Temp");
				
				$data .= $indent."\t".$gaccess.".push_back(".$arg['name']."Temp);\n";
				$data .= $indent."}\n";
			}
		}
		return ($data);
	}
	
	function arguments($data)
	{
		$args = "";
		foreach ($data as $arg)
		{
			if (strpos($arg['type'], '[') !== false && strpos($arg['type'], ']') !== false)
				$args .= ((!empty($args)) ? ', ' : '').'const '.explode('[', $arg['type'])[0]." *".$arg['name'];
			else
				$args .= ((!empty($args)) ? ', ' : '').'const '.$arg['type']." & ".$arg['name'];
		}
		return ($args);
	}
	
	
	function createCPP($class, $dir)
	{
		$name = 'Packet'.ucfirst($class['name']);
		
		$includes = array('<iostream>');
		array_push($includes, '"'.$name.'.hh"');
		
		// ----------------------- //

		// Includes
		$data = '';
		foreach ($includes as $include)
			$data .= "#include ".$include."\n";
	
		$args = arguments($class['arguments']);
		
		// Constructor from vars
    	$data .= "\n".$name.'::'.$name."(".$args.")\n{\n\tPacketSerializer ps;\n\tuint32_t dataPacketSize = 0;\n\n\t_type = IPacket::PacketType::".$class['type'].";\n\t_tickId = 0;\n";
		foreach ($class['arguments'] as $arg)
		{
			if (strpos($arg['type'], '[') !== false && strpos($arg['type'], ']') !== false)
			{
				$nb = explode(']', explode('[', $arg['type'])[1])[0];
				for ($x = 0; $x < $nb; $x++)
					$data .= "\t_".$arg['name']."[".$x."] = ".$arg['name']."[".$x."];\n";
			}
			else
				$data .= "\t_".$arg['name']." = ".$arg['name'].";\n";
			
		}

		$data .= create_serializer_code($class['arguments'], 0, '');
		
		$data .= "\n\t_data = ps.getPacket();\n\t_size = dataPacketSize;\n}\n\n";
		
		// Constructor from uint
		$posInPacket = (count($class['arguments']) > 0) ? "\tuint32_t posInPacket = 0;\n" : "";
		$data .= $name.'::'.$name."(const uint8_t *data)\n{\n\tPacketDeserializer pd(data);\n".$posInPacket."\n\t_type = IPacket::PacketType::".$class['type'].";\n\t_size = pd.getPacketSize();\n\t_tickId = pd.getPacketTickId();\n\n\t_data = new uint8_t[_size];\n\tfor (uint32_t a = 0; a < _size; a++)\n\t\t_data[a] = data[a + 9];\n";
		
		$data .= create_deserializer_code($class['arguments'], 0, '');
		
		$data .= "}\n\n";
				
		// Destructors
		$data .= $name."::~".$name."()\n{\n}";
	
	
		// Getters
		foreach ($class['arguments'] as $arg)
		{
			if (strpos($arg['type'], '[') !== false && strpos($arg['type'], ']') !== false)
				$data .= "\n\n".explode('[', $arg['type'])[0]." *".$name."::get".ucfirst($arg['name'])."()\n{\n\treturn (_".$arg['name'].");\n}";
			else
				$data .= "\n\n".$arg['type']." ".$name."::get".ucfirst($arg['name'])."() const\n{\n\treturn (_".$arg['name'].");\n}";
		}
		
		// isTcp()
		$data .= "\n\nbool ".$name."::isTcp() const\n{\n\treturn (".(($class['network'] == 'tcp') ? 'true' : 'false').");\n}";
		
		// isUdp()
		$data .= "\n\nbool ".$name."::isUdp() const\n{\n\treturn (".(($class['network'] == 'udp') ? 'true' : 'false').");\n}";
		
		
		$header = "//\n// This file was auto-generated, please do not edit it !\n//\n\n";
		file_put_contents($dir.$name.'.cpp', $header.$data);
	}
	
	function vector2name($vectorType)
	{
		$vectorType = explode('<', $vectorType)[1];
		$vectorType = explode('>', $vectorType)[0];
		$vectorType = str_replace('*', '', $vectorType);
		$name = ucfirst(trim($vectorType));
		return ($name);
	}
	
	function createDataHPP($class, $dir)
	{
		$vectorType = explode('<', $class['type'])[1];
		$vectorType = explode('>', $vectorType)[0];
		$vectorType = str_replace('*', '', $vectorType);
		$name = ucfirst(trim($vectorType));
		
		$includes = array('<stdint.h>');
		
		foreach ($class['vector'] as $arg)
		{
			if (strpos($arg['type'], 'std::vector') === 0 && !in_array('<vector>', $includes))
				array_push($includes, '<vector>');
			
			if (strpos($arg['type'], 'std::string') === 0 && !in_array('<string>', $includes))
				array_push($includes, '<string>');
		}
		
		$includes = array_merge($includes, recurs_search($class['vector']));
		
		$macro = strtoupper($name);
		
		// ----------------------- //
		
		// Ifndef macro
		$dataH = "#ifndef __".$macro."_HH__\n#define __".$macro."_HH__\n\n";

		// Includes
		foreach ($includes as $include)
			$dataH .= "#include ".$include."\n";
			
		// Namespace
		$dataH .= "\nnamespace Packet {\n\n";

		// Class
		$dataH .= "\tclass ".$name." {\n";
		
		// Public part
		$dataH .= "\n\tpublic:\n";
		
		// Constructors and destructors
    	$dataH .= "\t\t".$name."() {};\n\t\t~".$name."() {};\n\n";
    
		// Getters
		foreach ($class['vector'] as $arg)
			$dataH .= "\t\t".$arg['type']." get".ucfirst($arg['name'])."() const { return (_".$arg['name']."); };\n";
		$dataH .= "\n";
		// Setters
		foreach ($class['vector'] as $arg)
			$dataH .= "\t\tvoid set".ucfirst($arg['name'])."(const ".$arg['type']." & ".$arg['name'].") { _".$arg['name']." = ".$arg['name']."; };\n";
			
			
		// Protected part
		$dataH .= "\n\tprivate:\n";
			
		// Vars
		foreach ($class['vector'] as $arg)
			$dataH .= "\t\t".$arg['type']." _".$arg['name'].";\n";
		
		// Eend class
		$dataH .= "\t};";
		
		// Eend namespace
		$dataH .= "\n};";

		// endif
		$dataH .= "\n\n#endif";
		
		$header = "//\n// This file was auto-generated, please do not edit it !\n//\n\n";
		file_put_contents($dir.$name.'.hpp', $header.$dataH);
		
		createDataFrom($class['vector']);
	}

	
	function createDataFrom($args)
	{
		foreach ($args as $arg)
		{
			if (strpos($arg['type'], 'std::vector') === false)
				continue;
			createDataHPP($arg, 'common/include/packet_data/');
		}
	}
	
	$data = json_decode(file_get_contents('PacketList.json'), true);

	foreach ($data as $class)
	{
		createHH($class, 'common/include/packet/');
		createCPP($class, 'common/src/packet/');
		createDataFrom($class['arguments']);
	}