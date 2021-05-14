#!/bin/python2
from os.path import expanduser
from datetime import datetime
import time
import urllib2
from signal import signal, SIGPIPE, SIG_DFL
home = expanduser("~")
logfile = home + "/necha.log"
last = 5
now = datetime.now()
datime = now.strftime("%H:%M:%S %a, %d %b %Y")
def log(error):
    global last
    if error != 5:
        if error != last:
            print(error)
            if error == 0:
                f.write(datime + " Connected succefully\n")
            if error == 1:
                f.write(datime + " Failed connect\n")
        last = error
        signal(SIGPIPE,SIG_DFL)
def try_internet():
        while True:
            try:
                global last
                response = urllib2.urlopen("http://google.com",timeout=1)
                log(0)
                try_internet()
            except Exception:
                log(1)
            else:
                return

def main():
    pass
#time.sleep(5)


f = open(logfile, "a")
try_internet()
f.close()
