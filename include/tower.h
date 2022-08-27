#ifndef COLLIE_DEFENCE_GBA_TOWER_H
#define COLLIE_DEFENCE_GBA_TOWER_H

#include "bn_regular_bg_ptr.h"
#include "bn_regular_bg_item.h"
#include "bn_fixed.h"
#include "bn_optional.h"
#include "bn_core.h"
#include "bn_fixed_point.h"
#include "bn_camera_ptr.h"
#include "bn_vector.h"
#include "bn_memory.h"
#include "bn_format.h"
#include "bn_vector.h"
#include "bn_log.h"
#include "bn_math.h"
#include "bn_size.h"
#include "bn_unique_ptr.h"
#include "bn_sprite_builder.h"
#include "bn_sprite_ptr.h"
#include "bn_keypad.h"
#include "bn_fixed_rect.h"

#include "bn_sprite_items_tower.h"

#include "math.h"
#include "bullet.h"
#include "target.h"
#include "debug.h"

namespace cd
{
    class Level;
    class Tower
    {
    public:
        Tower(
            bn::camera_ptr camera,
            bn::fixed_point position);

        ~Tower();

        void on_tick(Level *level);
        void fire(Target *target);
        bn::vector<Bullet, 5> *get_bullets();
        bn::fixed_rect get_hitbox();

    private:
        bn::camera_ptr camera;
        bn::fixed_point position;
        bn::optional<bn::sprite_ptr>
            sprite;
        bn::optional<bn::timer> last_fire_timer;
        bn::vector<Bullet, 5> bullets;
        bn::fixed aggro_radius_px = 30;
    };
}

#endif
