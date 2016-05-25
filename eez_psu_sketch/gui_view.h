/*
 * EEZ PSU Firmware
 * Copyright (C) 2015-present, Envox d.o.o.
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.

 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.

 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

namespace eez {
namespace psu {
namespace gui {

#pragma pack(push, 1)

#define STYLE_FLAGS_BORDER 1
#define STYLE_FLAGS_HORZ_ALIGN 6
#define STYLE_FLAGS_HORZ_ALIGN_LEFT 0
#define STYLE_FLAGS_HORZ_ALIGN_RIGHT 2
#define STYLE_FLAGS_HORZ_ALIGN_CENTER 4
#define STYLE_FLAGS_VERT_ALIGN 24
#define STYLE_FLAGS_VERT_ALIGN_TOP 0
#define STYLE_FLAGS_VERT_ALIGN_BOTTOM 8
#define STYLE_FLAGS_VERT_ALIGN_CENTER 16

#define WIDGET_TYPE_NONE 0
#define WIDGET_TYPE_CONTAINER 1
#define WIDGET_TYPE_HORIZONTAL_LIST 2
#define WIDGET_TYPE_VERTICAL_LIST 3
#define WIDGET_TYPE_SELECT 4
#define WIDGET_TYPE_DISPLAY_DATA 5
#define WIDGET_TYPE_TEXT 6
#define WIDGET_TYPE_MULTILINE_TEXT 7
#define WIDGET_TYPE_BITMAP 8
#define WIDGET_TYPE_TOGGLE_BUTTON 9
#define WIDGET_TYPE_BUTTON_GROUP 10
#define WIDGET_TYPE_SCALE 11

typedef uint16_t OBJ_OFFSET;

struct List {
    uint8_t count;
    OBJ_OFFSET first;
};

struct Style {
    uint8_t font;
    uint16_t flags;
    uint16_t background_color;
    uint16_t color;
    uint16_t border_color;
    uint8_t padding_horizontal;
    uint8_t padding_vertical;
};

struct Widget {
    uint8_t type;
    uint8_t data;
    uint8_t action;
    uint16_t x;
    uint16_t y;
    uint16_t w;
    uint16_t h;
    OBJ_OFFSET style;
    OBJ_OFFSET specific;
};

struct ContainerWidget {
    List widgets;
};

struct ListWidget {
    OBJ_OFFSET item_widget;
};

struct SelectWidget {
    List widgets;
};

struct TextWidget {
    OBJ_OFFSET text;
};

struct MultilineTextWidget {
    OBJ_OFFSET text;
};

struct BitmapWidget {
    uint8_t bitmap;
};

struct ToggleButtonWidget {
    OBJ_OFFSET text1;
    OBJ_OFFSET text2;
};

struct ScaleWidget {
    uint8_t needle_height;
};

struct Document {
    List styles;
    List pages;
};

#pragma pack(pop)

}
}
} // namespace eez::psu::gui
