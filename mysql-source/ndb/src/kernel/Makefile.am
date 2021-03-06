# Copyright (C) 2004-2006 MySQL AB
# 
# This program is free software; you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation; version 2 of the License.
# 
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
# 
# You should have received a copy of the GNU General Public License
# along with this program; if not, write to the Free Software
# Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA

SUBDIRS = error blocks vm

include $(top_srcdir)/ndb/config/common.mk.am

ndbbin_PROGRAMS = ndbd

ndbd_SOURCES = main.cpp SimBlockList.cpp

include $(top_srcdir)/ndb/config/type_kernel.mk.am

INCLUDES += \
	-I$(srcdir)/blocks/cmvmi \
	-I$(srcdir)/blocks/dbacc \
	-I$(srcdir)/blocks/dbdict \
	-I$(srcdir)/blocks/dbdih \
	-I$(srcdir)/blocks/dblqh \
	-I$(srcdir)/blocks/dbtc \
	-I$(srcdir)/blocks/dbtup \
	-I$(srcdir)/blocks/ndbfs \
	-I$(srcdir)/blocks/ndbcntr \
	-I$(srcdir)/blocks/qmgr \
	-I$(srcdir)/blocks/trix \
	-I$(srcdir)/blocks/backup \
	-I$(srcdir)/blocks/dbutil \
	-I$(srcdir)/blocks/suma \
	-I$(srcdir)/blocks/dbtux

LDADD +=  \
              blocks/cmvmi/libcmvmi.a \
              blocks/dbacc/libdbacc.a \
              blocks/dbdict/libdbdict.a \
              blocks/dbdih/libdbdih.a \
              blocks/dblqh/libdblqh.a \
              blocks/dbtc/libdbtc.a \
              blocks/dbtup/libdbtup.a \
              blocks/ndbfs/libndbfs.a \
              blocks/ndbcntr/libndbcntr.a \
              blocks/qmgr/libqmgr.a \
              blocks/trix/libtrix.a \
              blocks/backup/libbackup.a \
              blocks/dbutil/libdbutil.a \
              blocks/suma/libsuma.a \
              blocks/dbtux/libdbtux.a \
              vm/libkernel.a	\
              error/liberror.a \
              $(top_builddir)/ndb/src/common/transporter/libtransporter.la   \
              $(top_builddir)/ndb/src/common/debugger/libtrace.la     \
              $(top_builddir)/ndb/src/common/debugger/signaldata/libsignaldataprint.la \
              $(top_builddir)/ndb/src/common/logger/liblogger.la       \
              $(top_builddir)/ndb/src/common/mgmcommon/libmgmsrvcommon.la \
              $(top_builddir)/ndb/src/mgmapi/libmgmapi.la \
              $(top_builddir)/ndb/src/common/portlib/libportlib.la      \
              $(top_builddir)/ndb/src/common/util/libgeneral.la  \
         $(top_builddir)/dbug/libdbug.a \
         $(top_builddir)/mysys/libmysys.a \
         $(top_builddir)/strings/libmystrings.a @NDB_SCI_LIBS@

# Don't update the files from bitkeeper
%::SCCS/s.%

windoze-dsp: ndbd.dsp

ndbd.dsp: Makefile \
               $(top_srcdir)/ndb/config/win-prg.am \
               $(top_srcdir)/ndb/config/win-name \
               $(top_srcdir)/ndb/config/win-includes \
               $(top_srcdir)/ndb/config/win-sources \
               $(top_srcdir)/ndb/config/win-libraries
	cat $(top_srcdir)/ndb/config/win-prg.am > $@
	@$(top_srcdir)/ndb/config/win-name $@ $(ndbbin_PROGRAMS)
	@$(top_srcdir)/ndb/config/win-includes $@ $(INCLUDES)
	@$(top_srcdir)/ndb/config/win-sources $@ $(ndbd_SOURCES)
	@$(top_srcdir)/ndb/config/win-libraries $@ LINK $(LDADD)
