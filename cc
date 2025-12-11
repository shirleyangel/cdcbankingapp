//vpc

cd Downloads/
sudo chmod 600 labsuser.pem

sudo scp -i labsuser.pem labsuser.pem ubuntu@3.80.26.190:/home/ubuntu/

sudo ssh -i labsuser.pem ubuntu@3.80.26.190
ls
// labsuser.pem
sudo chmod 600 labsuser.pem 
sudo apt-get update -y
sudo apt-get install apache2 php libapache2-mod-php php-mysql mysql-client -y
sudo git clone https://github.com/sreepathysois/Cafe_Dynamic_Website.git


 ls
Cafe_Dynamic_Website  labsuser.pem
ubuntu@ip-10-0-0-60:~$ cd Cafe_Dynamic_Website/mompopcafe/
ubuntu@ip-10-0-0-60:~/Cafe_Dynamic_Website/mompopcafe$ ls
AWSSDK  Dockerfile  css  getAppParameters.php  images  index.php  menu.php  orderHistory.php  processOrder.php  serverInfo.php
ubuntu@ip-10-0-0-60:~/Cafe_Dynamic_Website/mompopcafe$ sudo cp -rf * /var/www/html/.
ubuntu@ip-10-0-0-60:~/Cafe_Dynamic_Website/mompopcafe$ sudo rm -rf /var/www/html/index.html 
ubuntu@ip-10-0-0-60:~/Cafe_Dynamic_Website/mompopcafe$ sudo systemctl restart apache2
ubuntu@ip-10-0-0-60:~/Cafe_Dynamic_Website/mompopcafe$ cd
ubuntu@ip-10-0-0-60:~$ sudo ssh -i labsuser.pem ubuntu@10.0.1.44

sudo apt-get update -y
sudo apt-get install mysql-server -y
sudo mysql -u root -p

mysql> create database cafedb;
Query OK, 1 row affected (0.00 sec)

mysql> create user 'msis'@'%' identified by 'msis@123';
Query OK, 0 rows affected (0.02 sec)

mysql> grant all privileges on cafedb.* to 'msis'@'%';
Query OK, 0 rows affected (0.01 sec)

mysql> exit


ubuntu@ip-10-0-1-44:~$ sudo nano /etc/mysql/mysql.conf.d/mysqld.cnf 
ubuntu@ip-10-0-1-44:~$ sudo systemctl restart mysql
ubuntu@ip-10-0-1-44:~$ exit
logout
Connection to 10.0.1.44 closed.
ubuntu@ip-10-0-0-60:~$ sudo mysql -h 10.0.1.44 -u msis -p

show databases;
+--------------------+
| Database           |
+--------------------+
| cafedb             |
| information_schema |
| performance_schema |
+--------------------+
3 rows in set (0.01 sec)

mysql> exit
Bye
ubuntu@ip-10-0-0-60:~$ cd Cafe_Dynamic_Website/mompopdb
ubuntu@ip-10-0-0-60:~/Cafe_Dynamic_Website/mompopdb$ ls
Dockerfile  create-db.sh  create-db.sql  set-root-password.sh  sql
ubuntu@ip-10-0-0-60:~/Cafe_Dynamic_Website/mompopdb$ sudo mysql -h 10.0.1.44 -u msis -p



show databases;
+--------------------+
| Database           |
+--------------------+
| cafedb             |
| information_schema |
| performance_schema |
+--------------------+
3 rows in set (0.00 sec)

mysql> use cafedb;
Database changed
mysql> source create-db.sql;

show tables;
+------------------+
| Tables_in_cafedb |
+------------------+
| order            |
| order_item       |
| product          |
| product_group    |
+------------------+
4 rows in set (0.00 sec)

mysql> exit
Bye
ubuntu@ip-10-0-0-60:~/Cafe_Dynamic_Website/mompopdb$ cd /var/www/html
ubuntu@ip-10-0-0-60:/var/www/html$ ls
AWSSDK  Dockerfile  css  getAppParameters.php  images  index.php  menu.php  orderHistory.php  processOrder.php  serverInfo.php
ubuntu@ip-10-0-0-60:/var/www/html$ sudo nano getAppParameters.php 
ubuntu@ip-10-0-0-60:/var/www/html$ sudo systemctl restart apache2


//ebs
   ,     #_
   ~\_  ####_        Amazon Linux 2023
  ~~  \_#####\
  ~~     \###|
  ~~       \#/ ___   https://aws.amazon.com/linux/amazon-linux-2023
   ~~       V~' '->
    ~~~         /
      ~~._.   _/
         _/ _/
       _/m/'
[ec2-user@ip-10-1-11-88 ~]$ df -h
Filesystem      Size  Used Avail Use% Mounted on
devtmpfs        4.0M     0  4.0M   0% /dev
tmpfs           475M     0  475M   0% /dev/shm
tmpfs           190M  452K  190M   1% /run
/dev/xvda1      8.0G  1.6G  6.4G  20% /
tmpfs           475M     0  475M   0% /tmp
/dev/xvda128     10M  1.3M  8.7M  13% /boot/efi
tmpfs            95M     0   95M   0% /run/user/1000
[ec2-user@ip-10-1-11-88 ~]$ sudo file -s /dev/xvdf
/dev/xvdf: data
[ec2-user@ip-10-1-11-88 ~]$ sudo mkfs -t ext3 /dev/xvdf
mke2fs 1.46.5 (30-Dec-2021)
Creating filesystem with 262144 4k blocks and 65536 inodes
Filesystem UUID: 96d9c6be-7bed-446c-8dfb-84f262ca339b
Superblock backups stored on blocks: 
        32768, 98304, 163840, 229376

Allocating group tables: done                            
Writing inode tables: done                            
Creating journal (8192 blocks): done
Writing superblocks and filesystem accounting information: done

[ec2-user@ip-10-1-11-88 ~]$ sudo file -s /dev/xvdf
/dev/xvdf: Linux rev 1.0 ext3 filesystem data, UUID=96d9c6be-7bed-446c-8dfb-84f262ca339b (large files)
[ec2-user@ip-10-1-11-88 ~]$ sudo mkdir /mnt/myvolume
[ec2-user@ip-10-1-11-88 ~]$ sudo mount /dev/xvdf /mnt/myvolumes
mount: /mnt/myvolumes: mount point does not exist.
[ec2-user@ip-10-1-11-88 ~]$ sudo mount /dev/xvdf /mnt/myvolume
[ec2-user@ip-10-1-11-88 ~]$ df -h
Filesystem      Size  Used Avail Use% Mounted on
devtmpfs        4.0M     0  4.0M   0% /dev
tmpfs           475M     0  475M   0% /dev/shm
tmpfs           190M  448K  190M   1% /run
/dev/xvda1      8.0G  1.6G  6.4G  20% /
tmpfs           475M     0  475M   0% /tmp
/dev/xvda128     10M  1.3M  8.7M  13% /boot/efi
tmpfs            95M     0   95M   0% /run/user/1000
/dev/xvdf       975M   60K  924M   1% /mnt/myvolume
[ec2-user@ip-10-1-11-88 ~]$ cd /mnt/myvolume/
[ec2-user@ip-10-1-11-88 myvolume]$ sudo touch file.txt
[ec2-user@ip-10-1-11-88 myvolume]$ sudo chown -R ec2-user:ec2-user .
[ec2-user@ip-10-1-11-88 myvolume]$ cat >> file.txt
This is the ex for ebs vol
^C
[ec2-user@ip-10-1-11-88 myvolume]$ cat file.txt
This is the ex for ebs vol
[ec2-user@ip-10-1-11-88 myvolume]$ cd
[ec2-user@ip-10-1-11-88 ~]$ df -h
Filesystem      Size  Used Avail Use% Mounted on
devtmpfs        4.0M     0  4.0M   0% /dev
tmpfs           475M     0  475M   0% /dev/shm
tmpfs           190M  452K  190M   1% /run
/dev/xvda1      8.0G  1.6G  6.4G  20% /
tmpfs           475M     0  475M   0% /tmp
/dev/xvda128     10M  1.3M  8.7M  13% /boot/efi
tmpfs            95M     0   95M   0% /run/user/1000
/dev/xvdf       975M   64K  924M   1% /mnt/myvolume
[ec2-user@ip-10-1-11-88 ~]$ sudo file -s /dev/xvde
/dev/xvde: Linux rev 1.0 ext3 filesystem data, UUID=96d9c6be-7bed-446c-8dfb-84f262ca339b (needs journal recovery) (large files)
[ec2-user@ip-10-1-11-88 ~]$ sudo mkdir /mnt/resvolume
[ec2-user@ip-10-1-11-88 ~]$ sudo mount /dev/xvde /mnt/resvolume
[ec2-user@ip-10-1-11-88 ~]$ cd /mnt/resvolume
[ec2-user@ip-10-1-11-88 resvolume]$ ls
file.txt  lost+found
[ec2-user@ip-10-1-11-88 resvolume]$ 
Broadcast message from root@localhost (Fri 2025-09-12 05:05:17 UTC):

The system will power off now!

viva
 Here are **Cloud Foundation & Cloud Architecting Lab Viva Questions** — **short, neat, and exam-oriented**.

---

# ✅ **Cloud Foundation Viva Questions (Short)**

### **1. What is Cloud Computing?**

Delivery of computing services like **servers, storage, networking, databases, analytics** over the internet (*pay-as-you-go*).

### **2. What are the Cloud Service Models?**

* **IaaS** – Virtual servers, storage (e.g., EC2, EBS)
* **PaaS** – Runtime, database platforms (e.g., Elastic Beanstalk)
* **SaaS** – Ready-made applications (e.g., Gmail)

### **3. What are the Cloud Deployment Models?**

* **Public Cloud**
* **Private Cloud**
* **Hybrid Cloud**
* **Community Cloud**

### **4. What is Elasticity?**

Ability of cloud resources to **automatically increase or decrease** based on workload.

### **5. What is Scalability?**

Ability to **manually or automatically** increase resources to handle growth.

### **6. What is High Availability?**

System remains **operational with minimal downtime** using multiple AZs/resources.

### **7. What is Fault Tolerance?**

System continues to work **even if components fail** (multi-AZ, multi-region).

### **8. What is Auto Scaling?**

Automatically **adds/removes EC2 instances** based on demand.

### **9. What is a Region?**

Geographical area containing multiple **Availability Zones**.

### **10. What is an Availability Zone?**

Group of **isolated data centres** within a region.

### **11. What is VPC?**

Virtual Private Cloud — **isolated** network to run cloud resources.

### **12. What is a Subnet?**

Subdivision inside VPC; **public** (internet-facing) or **private**.

### **13. What is an Internet Gateway?**

Allows resources inside VPC to **connect to the internet**.

### **14. What is a NAT Gateway?**

Allows **private subnet** instances to access the internet **securely**.

### **15. What is IAM?**

Identity & Access Management — **controls access** to AWS services.

### **16. What is a Security Group?**

Virtual **firewall** for instances (stateful).

### **17. What is a NACL?**

Network ACL — subnet-level firewall (stateless).

### **18. What is S3?**

Object storage with **11 9's durability**, supports versioning & lifecycle.

### **19. What is CloudWatch?**

Monitoring service for **logs, metrics, alarms**.

### **20. What is CloudTrail?**

Tracks **API calls** for auditing.

---

# ✅ **Architecting on Cloud Viva Questions**

### **1. Principles of Cloud Architecture?**

* **Scalability**
* **Elasticity**
* **Fault Tolerance**
* **High Availability**
* **Automation**
* **Loose Coupling**
* **Security**

### **2. What is Well-Architected Framework?**

5 Pillars:

1. **Operational Excellence**
2. **Security**
3. **Reliability**
4. **Performance Efficiency**
5. **Cost Optimization**

### **3. What is Load Balancer?**

Distributes **incoming traffic** across multiple targets (ALB, NLB).

### **4. How to design a Highly Available application?**

* Use **multi-AZ** architecture
* Use **Auto Scaling**
* Use **Load Balancer**
* Use **RDS Multi-AZ**

### **5. What is a Stateless Application?**

App does not store session data locally; allows **scaling** easily.

### **6. What is Infrastructure as Code (IaC)?**

Provisioning using code tools like **CloudFormation, Terraform**.

### **7. Difference between Vertical & Horizontal Scaling?**

* **Vertical:** Increase instance size.
* **Horizontal:** Add more instances (preferred).

### **8. What is RDS Multi-AZ?**

Provides **high availability** by synchronously replicating data.

### **9. What is a CDN?**

Content Delivery Network — **delivers content faster** using edge locations (CloudFront).

### **10. What is Serverless?**

Services where you **don’t manage servers** (Lambda, DynamoDB, SQS).

### **11. When to use SQS?**

To decouple services using **message queues**.

### **12. What is Cloud Architecture Diagram?**

A design showing **compute, storage, networking, security, and data flow**.

### **13. What is Disaster Recovery (DR)?**

Strategy to recover services after failure.
DR Types:

* **Backup & Restore**
* **Pilot Light**
* **Warm Standby**
* **Multi-Site**

### **14. What is VPC Peering?**

Connects **two VPCs** privately.

### **15. What is Transit Gateway?**

Connects **multiple VPCs and on-prem networks** centrally.

### **16. What is Elastic Load Balancer Auto Scaling Architecture?**

* **Users → Load Balancer → Auto Scaling Group → EC2 Instances**

### **17. What is IAM Role?**

Temporary access permissions for AWS services.

### **18. What is Multi-Region Deployment?**

Deploying app across regions for **global availability** and DR.

### **19. What is Encryption at Rest & In Transit?**

* **At Rest:** Using KMS keys to secure stored data.
* **In Transit:** Using **TLS/HTTPS**.

### **20. What is API Gateway?**

Manages **REST APIs, throttling, caching, authentication**.

---

# ✅ Need **long answers**, **diagrams**, or **bold keywords** version?

I can format it exactly how your exam needs.








