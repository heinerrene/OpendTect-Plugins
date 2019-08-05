#
#   LocalAttrib Plugin
#   Copyright (C) 2019  Wayne Mogg
#

SET(OD_MODULE_DEPS AttributeEngine)
SET(OD_IS_PLUGIN yes)
SET(OD_MODULE_SOURCES
	ltfattrib.cc
	localattribpi.cc
	rsflib.cc
)

#IF( DEFINED ENV{RSFROOT} )
  add_definitions(-DNO_BLAS)
#  LIST( APPEND OD_MODULE_INCLUDESYSPATH $ENV{RSFROOT}/include )
#  LIST( APPEND OD_MODULE_EXTERNAL_LIBS $ENV{RSFROOT}/lib/libdrsf.so )
#ENDIF()

SET( OD_PLUGIN_ALO_EXEC ${OD_ATTRIB_EXECS} )
OD_INIT_MODULE()
