# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Dockerfile                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eugeniagleizer <marvin@42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/30 11:51:17 by eugeniagl         #+#    #+#              #
#    Updated: 2021/01/12 16:34:31 by phassan          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
FROM debian:buster

RUN apt-get update
RUN apt-get -y upgrade
RUN apt-get -y install
RUN apt-get -y install nginx
RUN apt-get -y install openssl
RUN apt-get -y install vim wget mariadb-server php7.3-fpm php7.3-mysql php7.3-mbstring curl

#ssl
RUN openssl req -subj '/CN=localhost' -x509 -newkey rsa:4096 -nodes -keyout /etc/ssl/private/localhost.key -out /etc/ssl/certs/localhost.crt -days 365

#nginx
COPY ./srcs/nginx-config ./etc/nginx/sites-available/localhost
RUN ln -s /etc/nginx/sites-available/localhost /etc/nginx/sites-enabled/localhost
RUN rm -rf /etc/nginx/sites-enabled/default

#phpmyadmin
RUN wget https://files.phpmyadmin.net/phpMyAdmin/4.9.7/phpMyAdmin-4.9.7-all-languages.tar.gz

RUN chmod -R 755 /var/www/*
RUN mkdir /var/www/localhost
RUN mkdir /var/www/localhost/phpmyadmin
RUN tar xvf phpMyAdmin-4.9.7-all-languages.tar.gz
RUN mv phpMyAdmin-4.9.7-all-languages/* /var/www/localhost/phpmyadmin
RUN rmdir phpMyAdmin-4.9.7-all-languages
RUN rm phpMyAdmin-4.9.7-all-languages.tar.gz
COPY ./srcs/config.inc.php /var/www/localhost/phpmyadmin/config.inc.php


#wordpress
RUN wget https://wordpress.org/latest.tar.gz
RUN tar -xzvf latest.tar.gz
RUN mkdir /var/www/localhost/wordpress
RUN mv wordpress/* /var/www/localhost/wordpress
RUN rmdir  wordpress
RUN rm latest.tar.gz
COPY ./srcs/wp-config.php /var/www/localhost/wordpress

EXPOSE 80 443

#run container
COPY ./srcs/run.sh ./
CMD bash ./run.sh
