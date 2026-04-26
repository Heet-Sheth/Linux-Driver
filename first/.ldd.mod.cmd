savedcmd_/home/ubuntu/ldd/first/ldd.mod := printf '%s\n'   ldd.o | awk '!x[$$0]++ { print("/home/ubuntu/ldd/first/"$$0) }' > /home/ubuntu/ldd/first/ldd.mod
