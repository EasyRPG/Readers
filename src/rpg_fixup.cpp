/*
 * This file is part of liblcf. Copyright (c) 2020 liblcf authors.
 * https://github.com/EasyRPG/liblcf - https://easyrpg.org
 *
 * liblcf is Free/Libre Open Source Software, released under the MIT License.
 * For the full copyright and license information, please view the COPYING
 * file that was distributed with this source code.
 */

#include "lcf/config.h"
#include "lcf/rpg/actor.h"
#include "lcf/rpg/mapinfo.h"
#include "lcf/rpg/system.h"
#include "lcf/rpg/save.h"
#include "lcf/rpg/savemapinfo.h"
#include "lcf/data.h"

template <typename T, typename U>
static void FixInt(T& val, U def) {
	if (val < 0) {
		val = def;
	}
};

template <typename T, typename U>
void UnFixInt(T& val, U def) {
	if (val == def) {
		val = -1;
	}
};

namespace lcf {

void rpg::SaveActor::Fixup(int actor_id) {
	ID = actor_id;

	const rpg::Actor& actor = lcf::Data::actors[actor_id - 1];

	if (name == "\x1") {
		name = ToString(actor.name);
	}
	if (title == "\x1") {
		title = ToString(actor.title);
	}
	if (sprite_name.empty()) {
		sprite_name = ToString(actor.character_name);
		sprite_id = actor.character_index;
		transparency = actor.transparent ? 3 : 0;
	}
	if (face_name.empty()) {
		face_name = ToString(actor.face_name);
		face_id = actor.face_index;
	}

	if (status.size() < lcf::Data::states.size()) {
		status.resize(lcf::Data::states.size());
	}
}

void rpg::SaveActor::UnFixup() {
	const rpg::Actor& actor = lcf::Data::actors[ID - 1];

	if (name == actor.name) {
		name = "\x1";
	}
	if (title == actor.title) {
		title = "\x1";
	}
	if (sprite_name == actor.character_name
			&& sprite_id == actor.character_index
			&& transparency == (actor.transparent ? 3 : 0)) {
		sprite_name.clear();
		sprite_id = 0;
		transparency = 0;
	}
	if (face_name == actor.face_name && face_id == actor.face_index) {
		face_name.clear();
		face_id = 0;
	}
}

void rpg::SaveSystem::Fixup() {
	const rpg::System& system = lcf::Data::system;

	switches.reserve(lcf::Data::switches.size());
	variables.reserve(lcf::Data::variables.size());
	if (battle_music.name.empty()) {
		battle_music = system.battle_music;
	}
	if (battle_end_music.name.empty()) {
		battle_end_music = system.battle_end_music;
	}
	if (inn_music.name.empty()) {
		inn_music = system.inn_music;
	}
	if (title_music.name.empty()) {
		title_music = system.title_music;
	}
	if (boat_music.name.empty()) {
		boat_music = system.boat_music;
	}
	if (ship_music.name.empty()) {
		ship_music = system.ship_music;
	}
	if (airship_music.name.empty()) {
		airship_music = system.airship_music;
	}
	if (gameover_music.name.empty()) {
		gameover_music = system.gameover_music;
	}
	if (cursor_se.name.empty()) {
		cursor_se = system.cursor_se;
	}
	if (decision_se.name.empty()) {
		decision_se = system.decision_se;
	}
	if (cancel_se.name.empty()) {
		cancel_se = system.cancel_se;
	}
	if (buzzer_se.name.empty()) {
		buzzer_se = system.buzzer_se;
	}
	if (battle_se.name.empty()) {
		battle_se = system.battle_se;
	}
	if (escape_se.name.empty()) {
		escape_se = system.escape_se;
	}
	if (enemy_attack_se.name.empty()) {
		enemy_attack_se = system.enemy_attack_se;
	}
	if (enemy_damaged_se.name.empty()) {
		enemy_damaged_se = system.enemy_damaged_se;
	}
	if (actor_damaged_se.name.empty()) {
		actor_damaged_se = system.actor_damaged_se;
	}
	if (dodge_se.name.empty()) {
		dodge_se = system.dodge_se;
	}
	if (enemy_death_se.name.empty()) {
		enemy_death_se = system.enemy_death_se;
	}
	if (item_se.name.empty()) {
		item_se = system.item_se;
	}
}

void rpg::SaveSystem::UnFixup() {
	const rpg::System& system = lcf::Data::system;

	auto reset_audio = [](auto& s) {
		s = {};
		s.name.clear();
	};

	if (battle_music == system.battle_music) {
		reset_audio(battle_music);
	}
	if (battle_end_music == system.battle_end_music) {
		reset_audio(battle_end_music);
	}
	if (inn_music == system.inn_music) {
		reset_audio(inn_music);
	}
	if (title_music == system.title_music) {
		reset_audio(title_music);
	}
	if (boat_music == system.boat_music) {
		reset_audio(boat_music);
	}
	if (ship_music == system.ship_music) {
		reset_audio(ship_music);
	}
	if (airship_music == system.airship_music) {
		reset_audio(airship_music);
	}
	if (gameover_music == system.gameover_music) {
		reset_audio(gameover_music);
	}
	if (cursor_se == system.cursor_se) {
		reset_audio(cursor_se);
	}
	if (decision_se == system.decision_se) {
		reset_audio(decision_se);
	}
	if (cancel_se == system.cancel_se) {
		reset_audio(cancel_se);
	}
	if (buzzer_se == system.buzzer_se) {
		reset_audio(buzzer_se);
	}
	if (battle_se == system.battle_se) {
		reset_audio(battle_se);
	}
	if (escape_se == system.escape_se) {
		reset_audio(escape_se);
	}
	if (enemy_attack_se == system.enemy_attack_se) {
		reset_audio(enemy_attack_se);
	}
	if (enemy_damaged_se == system.enemy_damaged_se) {
		reset_audio(enemy_damaged_se);
	}
	if (actor_damaged_se == system.actor_damaged_se) {
		reset_audio(actor_damaged_se);
	}
	if (dodge_se == system.dodge_se) {
		reset_audio(dodge_se);
	}
	if (enemy_death_se == system.enemy_death_se) {
		reset_audio(enemy_death_se);
	}
	if (item_se == system.item_se) {
		reset_audio(item_se);
	}
}


void rpg::SaveMapInfo::Fixup(const rpg::Map& map) {
	FixInt(chipset_id, map.chipset_id);
}

void rpg::SaveMapInfo::Fixup(const rpg::MapInfo& map) {
	FixInt(encounter_rate, map.encounter_steps);
}

void rpg::SaveMapInfo::UnFixup(const rpg::Map& map) {
	UnFixInt(chipset_id, map.chipset_id);
}

void rpg::SaveMapInfo::UnFixup(const rpg::MapInfo& map) {
	UnFixInt(encounter_rate, map.encounter_steps);
}

} // namespace lcf
