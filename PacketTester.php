<?php
	// ----------------
	// PacketTester 0.1
	// Maxime BACONNAIS
	// ----------------
	
	// TODO : Test Vector Packet
	
	$data = json_decode(file_get_contents('PacketList.json'), true);
	$test = "#include <iostream>\nint main() { std::cout << \"OK\" << std::endl; }";

	file_put_contents("test-compile.cpp", $test);
	
	function show_test($description, $status = false)
	{
		$mask = "%-50.50s %10.10s\n";
		printf($mask, $description, ($status ? 'OK' : $ko));
	}
	
	function arguments($args)
	{
		$data = '';
		foreach ($args as $arg)
		{
			if (!empty($data))
				$data .= ", ";
			if ($arg['type'] == 'std::string')
				$data .= "\"Bonjour je suis un petit lapin !\"";
			if ($arg['type'] == 'uint8_t')
				$data .= "255";
			if ($arg['type'] == 'uint16_t')
				$data .= "65535";
			if ($arg['type'] == 'uint32_t')
				$data .= "4294967295";
			if ($arg['type'] == 'uint8_t[4]')
			{
				return (false);
			}
			if ($arg['type'] == 'IPacket::PacketType')
				$data .= "IPacket::PacketType::WELCOME";
			if (strpos($arg['type'], 'std::vector') === 0)
			{
				return (false);
			}
		}
		return ($data);
	}
	
	$mask = "%-50.50s %10.10s\n";
	printf($mask, 'Description', 'Status');
	
	foreach ($data as $class)
	{
		$compile = shell_exec("g++ -W -Wall -Wextra -std=c++11 test-compile.cpp common/src/packet/Packet".ucfirst($class['name']).".cpp common/src/packet_tools/APacket.cpp common/src/packet_tools/PacketSerializer.cpp common/src/packet_tools/PacketDeserializer.cpp -I./common/include/packet/ -I./common/include/packet_tools/ -I./common/include/tools/ -I./common/include/packet_data/ && ./a.out\n");
		show_test("Compilation of Packet".ucfirst($class['name']), $compile == "OK\n");
	}
	unlink('test-compile.cpp');
	
	foreach ($data as $class)
	{
		$args = arguments($class['arguments']);
		
		if ($args === false)
		{
			//show_test("Basic tests for Packet".ucfirst($class['name']), false);
			continue;
		}
		
		$test = "		
#include <iostream>
#include \"Packet".ucfirst($class['name']).".hh\"

int main()
{\n";
if ($args != "")
	$test .="
	Packet".ucfirst($class['name'])." * packet1 = new Packet".ucfirst($class['name'])."(".$args.");
	Packet".ucfirst($class['name'])." * packet2 = new Packet".ucfirst($class['name'])."(packet1->generate());
	Packet".ucfirst($class['name'])." * packet3 = new Packet".ucfirst($class['name'])."(packet2->generate());
	
	";
	
	foreach ($class['arguments'] as $arg)
		$test .= "std::cout << ((packet1->get".ucfirst($arg['name'])."() == packet3->get".ucfirst($arg['name'])."()) ? \"OK\" : \"NOK\") << std::endl;\n\n";
$test .= "}";
		
		file_put_contents("test-basic.cpp", $test);
		$compile = shell_exec("g++ -W -Wall -Wextra -std=c++11 test-basic.cpp common/src/packet/Packet".ucfirst($class['name']).".cpp common/src/packet_tools/APacket.cpp common/src/packet_tools/PacketSerializer.cpp common/src/packet_tools/PacketDeserializer.cpp -I./common/include/packet/ -I./common/include/packet_tools/ -I./common/include/tools/ -I./common/include/packet_data/ && ./a.out\n");
		show_test("Basic tests for Packet".ucfirst($class['name']), strpos($compile, "NOK") === false);
	}
	
	unlink('test-basic.cpp');
	unlink('a.out');