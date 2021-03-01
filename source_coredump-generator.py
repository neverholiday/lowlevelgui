from glob import glob
import apport.hookutils

def add_info(report):
	
	report[ 'CrashDB' ] = '{ "impl":"ynxcrashdb", "distro" : "ubuntu" }'

	# apport.hookutils.attach_file_if_exists(report, APPORT_LOG, 'ApportLog')
	# reports = glob('/var/crash/*')
	# if reports:
	# 	report['CrashReports'] = apport.hookutils.command_output(
	# 		['stat', '-c', '%a:%u:%g:%s:%y:%x:%n'] + reports)

