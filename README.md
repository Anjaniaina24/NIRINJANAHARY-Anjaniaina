# NIRINJANAHARY-Anjaniaina
INSTALLATION D'APACHE2

    • Télécharger httpd-2.4.59.tar.gz dans le site https://httpd.apache.org/download.cgi#apache24
    • Décompresser et désarchiver le fichier source
        ◦ $ tar -xvf httpd-2.4.59.tar.gz
    • Entrez dans la répertoire httpd-2.4.59 qui vient d’être décompresser
    • Executer le fichier configure pour voir les dépendances et créer le Makefile
        ◦ $ ./configure
    • Il y a ensuite une erreur qui dit qu’il manque des bibliothèques alors il faut les télécharger 
        ◦ $ sudo apt install build-essential
        ◦ $ sudo apt install libssl-dev 
        ◦ $ sudo apt install libexpat1-dev 
        ◦ $ sudo apt install libpcre3-dev 
        ◦ $ sudo apt install libapr1-dev 
        ◦ $ sudo apt install libaprutil1-dev
    • Il faut vérifier s’il manque encore des dépendances
        ◦ $ ./configure
    • S’il n’y a pas d’erreur, compiler tous les codes sources
        ◦ $ make
    • Mettre les fichiers compilés dans leurs endroits respectives avec sudo car il a besoin d’aller dans les fichiers systèmes avec une autorisation du root
        ◦ $  sudo make install

INSTALLATION DE PHP

    • Télécharger php-8.3.6.tar.gz dans le site http://www.php.net/downloads.php
    • Décompresser et désarchiver le fichier source
        ◦ $ tar -xvf php-8.3.6.tar.gz
    • Entrez dans la répertoire php-8.3.6 qui vient d’être décompresser
    • Executer le fichier configure pour voir les dépendances et créer un Makefile
        ◦ $ ./configure
    • Il y a ensuite une erreur qui dit qu’il manque des bibliothèques alors il faut les télécharger 
        ◦ $ sudo apt install libxml2-dev
        ◦ $ sudo apt install lidsqlite3-dev
    • Il faut vérifier s’il manque encore des dépendances
        ◦ $ ./configure
    • S’il n’y a pas d’erreur, compiler tous les codes sources
        ◦ $ make
    • Mettre les fichiers compilés dans leurs endroits respectives avec sudo car il a besoin d’aller dans les fichiers systèmes avec une autorisation du root
        ◦ $  sudo make install


INSTALLATION DE MYSQL

    • Télécharger mysql-8.3.0.tar.gz dans le site 
      https://dev.mysql.com/downloads/mysql/
    • Décompresser et désarchiver le fichier source
        ◦ $ tar -xvf mysql-8.3.0.tar.gz
    • Entrez dans la répertoire mysql-8.3.0 qui vient d’être décompresser
    • Créer un repertoire build et ensuite dans cette repertoire
        ◦ $ mkdir build | cd build 
    • Il faut créer un « build system » à partir du commande « cmake », donc télécharger cmake et l’executer dans le repértoire courant
        ◦ $ sudo apt install cmake
        ◦ $ cmake ..
    • Compiler tous les codes sources
        ◦ $ make
    • Mettre les fichiers compilés dans leurs endroits respectives avec sudo car il a besoin d’aller dans les fichiers systèmes avec une autorisation du root­
        ◦ $  sudo make install
