#!/usr/bin/env python

from ictf import iCTF

i = iCTF("http://35.160.215.67/")
t = i.login("evanxia1018@gmail.com","B3Uy3rYgqza8")

key_info = t.get_ssh_keys()

with open("ctf_key", 'wb') as f:
    f.write(key_info['ctf_key'])

with open("root_key", 'wb') as f:
    f.write(key_info['root_key'])

print "IP: ", key_info['ip']
print "PORT: ", key_info['port']

# targets = t.get_targets(<service ID>)
