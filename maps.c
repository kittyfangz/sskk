/* maps.c
 **********
 * yes, all of this is hard coded. sorry
 * it's all terrible and engulfed in pain. and yet unless i begin again,
 * it remains my only option
 */

#include <ncurses.h>
#include <stdbool.h>
#include <string.h>

#include "sskk.h"
#include "maps.h"
#include "item.h"

/*** MAP 6 ***/

static void m6_events(int x, int y) {
	static bool revealed_note = false;
	if (x == 6 && y == 5) {
		write_message("Pro tip: use <a> to interact with things.");
	} else if (x == 6 && y == 3) {
		// what the FUCK is this shit
		int c = getch();
		switch (c) {
			case 'a':
				mvprintw(2, 6, ".");
				revealed_note = true;
				write_message("The button has been pressed down.");
				break;
		}
	} else if (x == 10 && y == 3 && revealed_note == true) {
		write_message("The note says: \"PAI-TA\".");
	} else if (x == 10 && y == 3) {
		write_message("The note says: \"PAI\"");
	} else if (x == 1 && y == 9) {
		warp_to(5, 18, 9);
	}
}

static void m6_draw_map(void) {
	mvprintw(1,  1, "-----------");
	mvprintw(2,  1, "|....u....|");
	mvprintw(3,  1, "|........=|");
	mvprintw(4,  1, "|.........|");
	mvprintw(5,  1, "-----.-----");
	mvprintw(6,  1, "    |.|");
	mvprintw(7,  1, "    |.|");
	mvprintw(8,  1, "-----.|");
	mvprintw(9,  1, "......|");
	mvprintw(10, 1, "-------");
}

/*** MAP 5 ***/

static void m5_events(int x, int y) {
	if (x == 1 && y == 2) {
		warp_to(4, 20, 5);
	} else if (x == 9 && y == 8) {
		write_message("The note says: \"ANAK ANAK EI\"");
	} else if (x == 11 && y == 8) {
		write_message("The note says: \"ANAK PAI\"");
	} else if (x == 19 && y == 9) {
		warp_to(6, 1, 9);
	}
}

static void m5_draw_map(void) {
	mvprintw(1, 1, "------");
	mvprintw(2, 1, ".....|");
	mvprintw(3, 1, "----.|");
	mvprintw(4, 1, "   |.|");
	mvprintw(5, 1, "   |.|");
	mvprintw(6, 1, "   |.|");
	mvprintw(7, 1, "   |.------------");
	mvprintw(8, 1, "   |....=.=.....|--");
	mvprintw(9, 1, "   |...............");
	mvprintw(10, 1,"   |............|--");
	mvprintw(11, 1,"   |............|");
	mvprintw(12, 1,"   |............|");
	mvprintw(13, 1,"   |............|");
	mvprintw(14, 1,"   |............|");
	mvprintw(15, 1,"   --------------");
}

/*** MAP 4 ***/

static void m4_events(int x, int y) {
	if (x == 1 && y == 5) {
		if (search_item("key") == 0)
			warp_to(3, 14, 2);
		else
			warp_to(2, 14, 2);
	} else if (x == 9 && y == 2) {
		write_message("The note says: \"ANAK ISIK WAN\"");
	} else if (x == 16 && y == 5 && search_item("key") == 0) {
		write_message("The door has been unlocked with the key.");
		mvprintw(5, 17, ".");
	} else if (x == 21 && y == 5) {
		warp_to(5, 2, 2);
	}
}

static void m4_draw_map(void) {
	mvprintw(1, 1, " ----------------");
	mvprintw(2, 1, " |......=.......|");
	mvprintw(3, 1, " |..............|");
	mvprintw(4, 1, "--..............-----");
	mvprintw(5, 1, "................+....");
	mvprintw(6, 1, "--..............-----");
	mvprintw(7, 1, " |..............|");
	mvprintw(8, 1, " |..............|");
	mvprintw(9, 1, " ----------------");
}

/*** MAP 3 ***/

static void m3_events(int x, int y) {
	if (x == 15 && y == 2) {
		warp_to(4, 2, 5);
	} else if (x == 2 && y == 2) {
		warp_to(0, 29, 4);
	}
}

static void m3_draw_map(void) {
	mvprintw(1,  1, "-----     ------");
	mvprintw(2,  1, "....|     |.....");
	mvprintw(3,  1, "--|.|-----|.|---");
	mvprintw(4,  1, "  |.........|   ");
	mvprintw(5,  1, "  -----.-----   ");
	mvprintw(6,  1, "      |.|       ");
	mvprintw(7,  1, "      |.|       ");
	mvprintw(8,  1, "  -----.-----   ");
	mvprintw(9,  1, "  |.........|   ");
	mvprintw(10, 1, "  |.........|   ");
	mvprintw(11, 1, "  |.........|   ");
	mvprintw(12, 1, "  |.........|   ");
	mvprintw(13, 1, "  -----------   ");
}

/*** MAP 2 ***/

static void m2_events(int x, int y) {
	if (x == 5 && y == 12 && search_item("key") == 1) {
		warp_to(3, 5, 12);
		pick_up((struct Item){"k", "key"});
		player.floor[0] = '.';
	} else if (x == 15 && y == 2) {
		warp_to(4, 2, 5);
	} else if (x == 2 && y == 2) {
		warp_to(0, 29, 4);
	}
}

static void m2_draw_map(void) {
	mvprintw(1,  1, "-----     ------");
	mvprintw(2,  1, "....|     |.....");
	mvprintw(3,  1, "--|.|-----|.|---");
	mvprintw(4,  1, "  |.........|   ");
	mvprintw(5,  1, "  -----.-----   ");
	mvprintw(6,  1, "      |.|       ");
	mvprintw(7,  1, "      |.|       ");
	mvprintw(8,  1, "  -----.-----   ");
	mvprintw(9,  1, "  |.........|   ");
	mvprintw(10, 1, "  |.........|   ");
	mvprintw(11, 1, "  |.........|   ");
	mvprintw(12, 1, "  |.k.......|   ");
	mvprintw(13, 1, "  -----------   ");
}

/*** MAP 1 ***/

static void m1_events(int x, int y) {
	if (x == 12 && y == 4) {
		warp_to(2, 12, 4);
		write_message("maybe you are missing something.");
	}
}

static void m1_draw_map(void) {
	mvprintw(1, 1, "-----     ------");
	mvprintw(2, 1, "|...|     |....|");
	mvprintw(3, 1, "--|.|-----|+|---");
	mvprintw(4, 1, "  |.........|   ");
	mvprintw(5, 1, "  -----------   ");
}

/*** MAP 0 ***/

static void m0_events(int x, int y) {
	static int turns = 0;
	static bool left = false;
	if (left == true) {
		write_message("The door has been locked behind you.");
	} else if (turns >= 1 && turns <= 3) {
		write_message("where have you ended up now?");
	} else if (player.floor[0] == 'o') {
		write_message("this is an Object. the Door is now gone.");
		mvprintw(4, 20, ".");
	} else if (y == 4 && x == 21) {
		write_message("you understand, now, what you need to do.");
	} 

	if (y == 4 && x == 30) {
		left = true;
		warp_to(2, 3, 2);
	}
	turns++;
}

static void m0_draw_map(void) {
	mvprintw(1, 1, "--------------------");
	mvprintw(2, 1, "|..................|");
	mvprintw(3, 1, "|..................|-----------");
	mvprintw(4, 1, "|...............o..+...........");
	mvprintw(5, 1, "|..................|-----------");
	mvprintw(6, 1, "|..................|");
	mvprintw(7, 1, "--------------------");
}

/*** BASE MAP CODE ***/

void check_events(int mapcode, int x, int y) {
	switch (mapcode) {
		case 0:
			m0_events(x, y);
			break;
		case 1:
			m1_events(x, y);
			break;
		case 2:
			m2_events(x, y);
			break;
		case 3:
			m3_events(x, y);
			break;
		case 4:
			m4_events(x, y);
			break;
		case 5:
			m5_events(x, y);
			break;
		case 6:
			m6_events(x, y);
		default:
			break;
	}
}

//recieves map code number
void draw_map(int mapcode) {
	erase();
	switch (mapcode) {
		case 0:
			m0_draw_map();
			break;
		case 1:
			m1_draw_map();
			break;
		case 2:
			m2_draw_map();
			break;
		case 3:
			m3_draw_map();
			break;
		case 4:
			m4_draw_map();
			break;
		case 5:
			m5_draw_map();
			break;
		case 6:
			m6_draw_map();
			break;
		default:
			write_message("error in draw_map: invalid mapcode");
			break;
	}
}
