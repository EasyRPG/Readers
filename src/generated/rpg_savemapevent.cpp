/* !!!! GENERATED FILE - DO NOT EDIT !!!! */

/*
 * Copyright (c) 2015 liblcf authors
 * This file is released under the MIT License
 * http://opensource.org/licenses/MIT
 */

// Headers
#include "rpg_savemapevent.h"

/**
 * Constructor.
 */
RPG::SaveMapEvent::SaveMapEvent() {
	ID = 0;
	active = true;
	map_id = -1;
	position_x = -1;
	position_y = -1;
	prelock_direction = 2;
	direction = 2;
	anim_frame = 1;
	unknown_18 = 0;
	unknown_1f = 0;
	move_frequency = -1;
	layer = 1;
	overlap_forbidden = false;
	animation_type = 1;
	lock_facing = false;
	move_speed = -1;
	move_route_overwrite = false;
	move_route_index = 0;
	move_route_repeated = false;
	unknown_2f_overlap = -1;
	anim_paused = 0;
	unknown_33 = 0;
	unknown_34 = 0;
	unknown_35 = 0;
	unknown_36 = 0;
	unknown_3d = 0;
	unknown_3e = 0;
	unknown_3f = 0;
	unknown_47 = 0;
	flying = false;
	sprite_name = "";
	sprite_id = -1;
	unknown_4b = -1;
	flash_red = 100;
	flash_green = 100;
	flash_blue = 100;
	flash_current_level = 0.0;
	flash_time_left = 0;
	unknown_65 = 0;
	original_move_route_index = 0;
	unknown_67 = -1;
}
