//
// C:\Users\Guimauve\Documents\RType\common\src\tools\RunTimeError.cpp for RType in
//
// Made by La Guimauve
// Login   <rembur_g@epitech.eu>
//
// Started on  Tue Dec 20 11:04:37 2016 La Guimauve
// Last update Tue Dec 20 11:09:23 2016 La Guimauve
//

#include "RunTimeError.hh"

RunTimeError::RunTimeError(const std::string &err, const std::string &cl) : AError(err, cl) {}

RunTimeError::RunTimeError(const std::string &err) : AError(err) {}

RunTimeError::RunTimeError(const AError &err) : AError(err) {}