/*
The MIT License (MIT)

Copyright (c) 2014 holmes

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/


#include "scriptengine.h"
#include "lua-5.2.3/lua.hpp"
#include "configini.h"

#include <QString>
#include <QMessageBox>


static lua_State *L = NULL;

ScriptEngine* ScriptEngine::Instance()
{
    static ScriptEngine _instance;
    return &_instance;
}


void ScriptEngine::setup()
{
    L = luaL_newstate();
    luaL_openlibs(L);

    QSettings *setting = ConfigIni::Instance()->getConfigFile();
    setting->beginGroup("base");
    QString ss = setting->value("lua").toString();

    if (luaL_dofile(L, ss.toLocal8Bit()))
        QMessageBox::about(NULL, "Waring", QString("load lua file fail : ").append(ss));
}


void ScriptEngine::cleanup()
{
    if (L)
    {
        lua_close(L);
        L = NULL;
    }
}
