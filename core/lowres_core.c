//
// Copyright 2016 Timo Kloss
//
// This file is part of LowRes Core.
//
// LowRes Core is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// LowRes Core is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Lesser General Public License for more details.
//
// You should have received a copy of the GNU Lesser General Public License
// along with LowRes Core.  If not, see <http://www.gnu.org/licenses/>.
//

#include "lowres_core.h"
#include <stdlib.h>

void LRC_init(LRCore *core)
{
    core->videoInterface.colors[0] = 3;
    core->videoInterface.colors[1] = 12;
    core->videoInterface.colors[2] = 48;
    core->videoInterface.colors[3] = 63;
    core->videoInterface.colors[5] = 20;
    core->videoInterface.colors[6] = 25;
    core->videoInterface.colors[7] = 12;
    core->videoInterface.colors[11] = 48;
    core->videoInterface.colors[15] = 60;
    
    Window *window = &core->videoInterface.window;
    window->cells[0][0].character = 'S';
    window->cells[0][1].character = 'C';
    window->cells[0][2].character = 'O';
    window->cells[0][3].character = 'R';
    window->cells[0][4].character = 'E';
    window->cells[0][5].character = 255;
    window->cells[0][6].character = 254;
    window->cells[0][7].character = 253;
    
    Sprite *sprite = &core->videoInterface.sprites[0];
    sprite->character = 252;
    sprite->attr_palette = 1;
    sprite->attr_priority = 1;
}

void LRC_update(LRCore *core)
{
    core->videoInterface.planes[0].scrollX--;
    core->videoInterface.planes[1].scrollY--;
    int pli = rand()%2;
    Cell *cell = &core->videoInterface.planes[pli].cells[rand()%32][rand()%32];
    cell->character = 32+(rand()%32);
    cell->attr_palette = rand()%4;
    cell->attr_priority = rand()%2;
    
    Sprite *sprite = &core->videoInterface.sprites[0];
    sprite->x += 2;
    sprite->y += 2;
}
