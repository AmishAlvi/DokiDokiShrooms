#include "Banks/SetAutoBank.h"
#include "Keys.h"
#include "SpriteManager.h"
#include "ZGBMain.h"

const UINT8 anim_idle[] = {1, 0}; //The first number indicates the number of frames
const UINT8 anim_walk[] = {2, 1, 2};

Sprite* carried_mush = 0;

void START() {
    carried_mush = 0;
}

void UPDATE() {

    UINT8 i;
	Sprite* spr;



	if(KEY_PRESSED(J_UP)) {
		TranslateSprite(THIS, 0 , -1);
        SetSpriteAnim(THIS, anim_walk, 15);
	} 
	if(KEY_PRESSED(J_DOWN)) {
		TranslateSprite(THIS, 0 , 1);
        SetSpriteAnim(THIS, anim_walk, 15);
	}
	if(KEY_PRESSED(J_LEFT)) {
		TranslateSprite(THIS, -1, 0);
        SetSpriteAnim(THIS, anim_walk, 15);
	}
	if(KEY_PRESSED(J_RIGHT)) {
		TranslateSprite(THIS, 1 , 0);
        SetSpriteAnim(THIS, anim_walk, 15);
	}

    if (keys == 0)
    {
        SetSpriteAnim(THIS, anim_idle, 15);
    }

    if (carried_mush != 0) {
        // We are holding a mushroom! Force it to stay above the player.
        // Adjust the '- 8' to change how high above the player's head it sits.
        carried_mush->x = THIS->x - 1;
        carried_mush->y = THIS->y - 14; 
        
        // Optional: Drop the mushroom if we press B
        if (KEY_PRESSED(J_B)) {
            carried_mush = 0; // Let go of it!
        }
    } 
    else {
        // --- PICKUP LOGIC ---
        // Only check for pickup if we aren't already carrying one
        SPRITEMANAGER_ITERATE(i, spr) {
            if (spr->type == SpriteMush) {
                if (CheckCollision(THIS, spr)) {
                    if (KEY_PRESSED(J_A)) {
                        // 2. We picked it up! Save the reference.
                        carried_mush = spr;
                        
                        // Optional: Add a little "bloop" sound effect for game feel!
                        // PlayFx(CHANNEL_1, 10, 50, 80, 128, 0); 
                        
                        // Break out of the loop since we found our mushroom
                        break; 
                    }
                }
            }
        }
    }
}

void DESTROY() {
}