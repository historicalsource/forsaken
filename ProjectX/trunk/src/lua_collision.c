/* Lua bindings for collision detection functions.
 *
 * collided, endpos, endgroup, normal, newtarget =
 *     bgcollide(startpos, startgroup, move_off, bgcol)
 *
 * see also collision.h
 */
#include <lua.h>
#include <lauxlib.h>
#include "object.h" /* FIXME: needed by collision.h */
#include "collision.h"

extern MCLOADHEADER MCloadheadert0;
extern MLOADHEADER Mloadheader;

/* [-0, +1, m] */
#define NEWOBJ(L, objtype, var) do {           \
	var = lua_newuserdata(L, sizeof(objtype)); \
	luaL_getmetatable(L, #objtype);            \
	lua_setmetatable(L, -2);                   \
} while (0)

/* TODO - move this function to lua_vecmat.c and export it? */
static void lua_pushvector(lua_State *L, VECTOR *v)
{
	VECTOR *nv = lua_newuserdata(L, sizeof(VECTOR));
	nv->x = v->x;
	nv->y = v->y;
	nv->z = v->z;
	luaL_getmetatable(L, "VECTOR");
	lua_setmetatable(L, -2);
}

static int luacoll_bgcollide(lua_State *L)
{
	VECTOR *startpos, *move_off, *endpos, *normal, *newtarget;
	uint16 startgroup, endgroup;
	BOOL bgcol;

	/* get input parameters */
	startpos = luaL_checkudata(L, 1, "VECTOR");
	startgroup = luaL_checkint(L, 2);
	move_off = luaL_checkudata(L, 3, "VECTOR");
	(void) luaL_checkint(L, 4);
	bgcol = lua_toboolean(L, 4);

	/* initialize userdata memory for output values */
	NEWOBJ(L, VECTOR, endpos);
	NEWOBJ(L, VECTOR, normal);
	NEWOBJ(L, VECTOR, newtarget);

	/* call collision check function and push result as first output value */
	lua_pushboolean(L,
		BackgroundCollide(
			&MCloadheadert0, &Mloadheader, /* fixed arguments */
			startpos, startgroup, move_off, /* inputs */
			endpos, &endgroup, (NORMAL *) normal, newtarget, /* outputs */
			bgcol, NULL
		)
	);

	/* finally, push the other outputs */
	lua_pushvector(L, endpos);
	lua_pushinteger(L, endgroup);
	lua_pushvector(L, normal);
	lua_pushvector(L, newtarget);

	return 5;
}

int luaopen_collision(lua_State *L)
{
	static const luaL_Reg funcs[] = {
		{ "bgcollide", luacoll_bgcollide },
		{ NULL, NULL }
	};
	int i;

	for (i=0; funcs[i].name; i++)
	{
		lua_pushcfunction(L, funcs[i].func);
		lua_setglobal(L, funcs[i].name);
	}

	return 0;
}