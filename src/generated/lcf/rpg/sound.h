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

#ifndef LCF_RPG_SOUND_H
#define LCF_RPG_SOUND_H

// Headers
#include <stdint.h>
#include <string>
#include <ostream>
#include <type_traits>

/**
 * rpg::Sound class.
 */
namespace lcf {
namespace rpg {
	class Sound {
	public:
		std::string name = "(OFF)";
		int32_t volume = 100;
		int32_t tempo = 100;
		int32_t balance = 50;

		template <typename F>
		void ForEachString(const F& f);
	};

	inline bool operator==(const Sound& l, const Sound& r) {
		return l.name == r.name
		&& l.volume == r.volume
		&& l.tempo == r.tempo
		&& l.balance == r.balance;
	}

	inline bool operator!=(const Sound& l, const Sound& r) {
		return !(l == r);
	}

	std::ostream& operator<<(std::ostream& os, const Sound& obj);

	template <typename F>
	inline void Sound::ForEachString(const F& f) {
		name = f(name, "name");
	}
} // namespace rpg
} // namespace lcf

#endif
