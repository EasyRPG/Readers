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

#ifndef LCF_RPG_ANIMATIONFRAME_H
#define LCF_RPG_ANIMATIONFRAME_H

// Headers
#include <vector>
#include "lcf/rpg/animationcelldata.h"
#include <ostream>
#include <type_traits>

/**
 * rpg::AnimationFrame class.
 */
namespace lcf {
namespace rpg {
	class AnimationFrame {
	public:
		int ID = 0;
		std::vector<AnimationCellData> cells;

		template <typename F>
		void ForEachString(const F& f);
	};

	inline bool operator==(const AnimationFrame& l, const AnimationFrame& r) {
		return l.cells == r.cells;
	}

	inline bool operator!=(const AnimationFrame& l, const AnimationFrame& r) {
		return !(l == r);
	}

	std::ostream& operator<<(std::ostream& os, const AnimationFrame& obj);

	template <typename F>
	inline void AnimationFrame::ForEachString(const F& f) {
		(void)f;
	}
} // namespace rpg
} // namespace lcf

#endif
