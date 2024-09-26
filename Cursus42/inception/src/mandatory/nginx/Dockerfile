FROM debian:buster

RUN apt-get update && apt-get install -y nginx openssl

RUN mkdir /etc/nginx/ssl
RUN openssl req -x509 -newkey rsa:4096 \
-keyout /etc/nginx/ssl/mdreesen.key \
-out /etc/nginx/ssl/mdreesen.crt -sha256 -days 3650 -nodes \
-subj "/C=BE/ST=NaN/L=Peer/O=Campus19/OU=mdreesen/CN=mdreesen/"

COPY ./config/nginx.conf /etc/nginx/conf.d

RUN mkdir -p /run/nginx

EXPOSE 443

CMD [ "nginx", "-g", "daemon off;"]