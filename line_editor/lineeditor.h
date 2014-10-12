#ifndef _LINEEDITOR_H_
#define _LINEEDITOR_H_

#include <string>

namespace restonce{
	/*
	 * change the command and charators to normal charators
	 * 	'#' 	: delete a recent charactor
	 * 	'@'	: delete all privours charators
	 * */
	std::string line_editor(const std::string& input);
}

#endif
