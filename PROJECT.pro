TEMPLATE = app
CONFIG   += console
CONFIG   -= app_bundle
CONFIG   -= qt

SOURCES  += \
         sqlite3.c \
    main.c \
    tables.c \
    crud.c

HEADERS  += \
         sqlite3.h \
    tables.h \
    crud.h
