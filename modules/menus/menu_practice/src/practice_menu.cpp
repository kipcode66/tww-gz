#include "menus/menu_practice/include/practice_menu.h"
#include "gz_flags.h"
#include "rels/include/defines.h"
#include "menus/utils/menu_mgr.h"

KEEP_FUNC PracticeMenu::PracticeMenu(Cursor& cursor)
    : Menu(cursor), lines{
                        {"any\%", ANY_OPTIMAL, "Load an any\% save", false},
                        {"any\% no mss", ANY_NO_MSS, "Load an any\% no mss save", false},
                        {"all dungeons", ALL_DUNGEONS, "Load an all dungeons save", false},
                        {"any\% (bombs first, no pg skip)", ANY_PERCENT, "Load an any\% save", false},
                    } {}

PracticeMenu::~PracticeMenu() {}

void PracticeMenu::draw() {
    if (GZ_getButtonTrig(BACK_BUTTON)) {
        g_menuMgr->pop();
        return;
    }

    if (GZ_getButtonTrig(SELECTION_BUTTON)) {
        switch (cursor.y) {
        case ANY_OPTIMAL:
            g_menuMgr->push(MN_ANY_OPTIMAL_SAVES_INDEX);
            return;
        case ANY_NO_MSS:
            g_menuMgr->push(MN_ANY_NOMSS_SAVES_INDEX);
            return;
        case ALL_DUNGEONS:
            g_menuMgr->push(MN_AD_SAVES_INDEX);
            return;
        case ANY_PERCENT:
            g_menuMgr->push(MN_ANY_SAVES_INDEX);
            return;
        }
    }

    cursor.move(0, MENU_LINE_NUM);
    GZ_drawMenuLines(lines, cursor.y, MENU_LINE_NUM);
}
