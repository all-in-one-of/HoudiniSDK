TARGET=geoisosurface
SOURCES+=$$PWD/geoisosurface.cpp \
         $$PWD/SDFunctions.cpp
HEADERS+=$$PWD/SDFunctions.h
QT-=core gui
CONFIG-=app_bundle
CONFIG+=c++11
macx{
INCLUDEPATH+=/Library/Frameworks/Houdini.framework/Versions/Current/Resources/toolkit/include
QMAKE_CXXFLAGS= -DVERSION=\"15.5.717\" -D_GNU_SOURCE -DMBSD -DMBSD_COCOA -DMBSD_INTEL -arch x86_64 -DAMD64 -fPIC -DSIZEOF_VOID_P=8 -DFBX_ENABLED=1 -DOPENCL_ENABLED=1 -DOPENVDB_ENABLED=1 -DSESI_LITTLE_ENDIAN -DENABLE_THREADS -DUSE_PTHREADS -D_REENTRANT -D_FILE_OFFSET_BITS=64 -c -mmacosx-version-min=10.12 -DGCC4 -DGCC3 -Wno-deprecated -stdlib=libc++ -std=c++11 -isystem /Library/Frameworks/Houdini.framework/Versions/Current/Resources/toolkit/include -Wall -W -Wno-parentheses -Wno-sign-compare -Wno-reorder -Wno-uninitialized -Wunused -Wno-unused-parameter -Wno-unused-local-typedefs -O2
LIBS+=-arch x86_64 -fobjc-gc -framework OpenGL -framework Cocoa
LIBS+= -L/Library/Frameworks/Houdini.framework/Versions/Current/Libraries -lHoudiniUI -lHoudiniOPZ -lHoudiniOP3 -lHoudiniOP2 -lHoudiniOP1 -lHoudiniSIM -lHoudiniGEO -lHoudiniPRM -lHoudiniUT -lboost_system
LIBS+= -Wl,-rpath,/Library/Frameworks/Houdini.framework/Versions/Current/Libraries
}

linux{
QMAKE_CXXFLAGS=-DVERSION=\"15.5.686\" -D_GNU_SOURCE -DLINUX -DAMD64 -m64 -fPIC -DSIZEOF_VOID_P=8 -DFBX_ENABLED=1 -DOPENCL_ENABLED=1 -DOPENVDB_ENABLED=1 -DSESI_LITTLE_ENDIAN -DENABLE_THREADS -DUSE_PTHREADS -D_REENTRANT -D_FILE_OFFSET_BITS=64 -c -DGCC4 -DGCC3 -Wno-deprecated -std=c++11 -isystem /opt/hfs15.5.686/toolkit/include -Wall -W -Wno-parentheses -Wno-sign-compare -Wno-reorder -Wno-uninitialized -Wunused -Wno-unused-parameter -Wno-unused-local-typedefs -O2 -fno-strict-aliasing
LIBS+=-L/usr/X11R6/lib64 -L/usr/X11R6/lib -lGLU -lGL -lX11 -lXext -lXi -ldl
LIBS+= -L/opt/hfs15.5.686/dsolib/  -lHoudiniUI -lHoudiniOPZ -lHoudiniOP3 -lHoudiniOP2 -lHoudiniOP1 -lHoudiniSIM -lHoudiniGEO -lHoudiniPRM -lHoudiniUT -lboost_system

}
