mod_log_millisecond.la: mod_log_millisecond.slo
	$(SH_LINK) -rpath $(libexecdir) -module -avoid-version  mod_log_millisecond.lo
DISTCLEAN_TARGETS = modules.mk
shared =  mod_log_millisecond.la
