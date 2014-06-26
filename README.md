An apache module enable to log request time in milliseconds 

## USAGE

```
LoadModule log_millisecond_module modules/mod_log_millisecond.so

# add '%M' to LogFormat
LogFormat "%M %h %l %u %t \"%r\" %>s %b \"%{Referer}i\" \"%{User-Agent}i\" x-common
```

This is sample.

```
0.0 127.0.0.1 - - [26/Jun/2014:15:11:23 +0900] "GET /index.html HTTP/1.1" 200 44
```

