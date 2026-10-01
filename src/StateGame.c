#include "Banks/SetAutoBank.h"

#include "ZGBMain.h"
#include "Scroll.h"
#include "SpriteManager.h"

IMPORT_MAP(map);
IMPORT_MAP(hud);

UINT8 collision_tiles[] = {1,0};

void START() {
	INIT_HUD(hud);
	scroll_target = SpriteManagerAdd(SpritePlayer, 50, 50);
	SpriteManagerAdd(SpriteMush, 70, 50);
	InitScroll(BANK(map), &map, collision_tiles, 0);
}

void UPDATE() {
}
