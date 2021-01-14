# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    run.sh                                             :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: phassan <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/11 13:51:56 by phassan           #+#    #+#              #
#    Updated: 2021/01/12 15:25:44 by phassan          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

service mysql start

echo "CREATE DATABASE wordpress;" | mysql -u root --skip-password
echo "USE wordpress;" | mysql -u root --skip-password
echo "GRANT ALL PRIVILEGES ON wordpress.* TO 'root'@'localhost' WITH GRANT OPTION;" | mysql -u root --skip-password
echo "update mysql.user set plugin='mysql_native_password' where user='root';" | mysql -u root --skip-password
echo "FLUSH PRIVILEGES;" | mysql -u root --skip-password
echo "EXIT" | mysql -u root --skip-password


#mysql -u root -p
#mysql -u root --skip-password > CREATE DATABASE wordpress;
#mysql -u root --skip-password > USE wordpress;
#mysql -u root --skip-password > GRANT ALL PRIVILEGES ON wordpress.* TO 'root'@'localhost' WITH GRANT OPTION;
#mysql -u root --skip-password > update mysql.user set plugin='mysql_native_password' where user='root';
#mysql -u root --skip-password > FLUSH PRIVILEGES;
#mysql -u root --skip-password > EXIT;

service php7.3-fpm start
service nginx start

bash
