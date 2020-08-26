/* !!!! GENERATED FILE - DO NOT EDIT !!!!
 * --------------------------------------
 *
 * This file is part of liblcf. Copyright (c) 2020 liblcf authors.
 * https://github.com/EasyRPG/liblcf - https://easyrpg.org
 *
 * liblcf is Free/Libre Open Source Software, released under the MIT License.
 * For the full copyright and license information, please view the COPYING
 * file that was distributed with this source code.
 */

#ifndef LCF_RPG_EVENT_H
#define LCF_RPG_EVENT_H

// Headers
#include <stdint.h>
#include <vector>
#include "lcf/dbstring.h"
#include "lcf/rpg/eventpage.h"
#include <ostream>
#include <type_traits>

/**
 * rpg::Event class.
 */
namespace lcf {
namespace rpg {
	class Event {
	public:
		int ID = 0;
		DBString name;
		int32_t x = 0;
		int32_t y = 0;
		std::vector<EventPage> pages;
	};

	inline bool operator==(const Event& l, const Event& r) {
		return l.name == r.name
		&& l.x == r.x
		&& l.y == r.y
		&& l.pages == r.pages;
	}

	inline bool operator!=(const Event& l, const Event& r) {
		return !(l == r);
	}

	std::ostream& operator<<(std::ostream& os, const Event& obj);
} // namespace rpg
} // namespace lcf

#endif
