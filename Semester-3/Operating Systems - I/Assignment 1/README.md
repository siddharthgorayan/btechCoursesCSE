# Homework Assignment 1
## Operating System Setup Last edited: Oct 25th. 2020.
### Learning objectives of this assignment are:

● Basic OS (Linux & DOS) setup and administration skills.

● Linux administration skills will be useful for many years to come.

● Linux skills will also be useful for automation using bash shell scripting (assignment#2).

● DOS skills will be required for setting up 8086 assembly language programming environment
setup (Microsoft assembler, Turbo assembler) during Computer Organization course.

● DOS skill will also be useful for using batch scripting in DOS/Windows (assignment#2).

● DOS and Yocto (a slim linux) are predominantly used firmware OSes (eg IOT devices).


## Task 1​: 

Create a Debian 10 Virtual Machine (VM) using Linux virt-manager (QEMU-KVM) on your local host (laptop/desktop). If you are using Windows, you could use WSL and run virt-manager on it or use VirtualBox. If you are using Mac, you could use VirtualBox. If your laptop is low on resources, please feel free to ask for a VM from department cloud.

● Create a VM with 

○ 2CPU

○ 1GB RAM

○ One hard-disk drive (10GB).

○ One CD drive

● Download debian 10 (amd64) CD image from ​here​.

● Install Debian 10 on hard disk drive.

● Run the following command inside the VM

○ sudolshw>debian-lshw.txt

● Run the one of the following command on the host ○ virshdumpxmlvmname>qemu-debian.txt

○ vboxmanageshowvminfovmname>vbox-debian.txt

● Submit the ​debian-lshw.txt and qemu-debian.txt​ files (not docx, pdf)


## Task 2​: 

Create a FreeDOS Virtual Machine (VM) using Linux virt-manager (QEMU-KVM) on your local host (laptop/desktop). If you are using Windows, you could use WSL and run virt-manager on it or use VirtualBox. If you are using Mac, you could use VirtualBox. If your laptop is low on resources, please feel free to ask for a VM from department cloud.

● Create a VM with 

○ 1CPU

○ 64MB RAM

○ One hard-disk drive (1GB).

○ One floppy drive (A:) backed by a floppy image (1.44MB each) Hint: use ​qemu-img create​ command.

○ One CD drive

● Download freedos 1.2 CD image from ​here​.

● Install Freedos 1.2 on hard disk drive. ​Install Howto

● Run the one of the following command on the host

○ virshdumpxmlvmname>qemu-freedos.txt

○ vboxmanageshowvminfovmname>vbox-freedos.txt

## Deliverables:

1​.​ ​Upload all the files in submission URL ​http://jenkins.cse.iith.ac.in:8080​ Goto “Auto-Grader” ⇒ “2020-OS-I” ⇒ “rollno” ⇒ HW-Assignment01-OSsetup ⇒ “Build with Parameters” ⇒ upload files and accept plagiarism statement ⇒ “Build”. Dont forget to accept the “Plagiarism statement”. Please dont email the submission files, and dont upload zip/tar/gz files.
 
2.​ ​Post any queries in Great Learning discussion forum for assignment 1. Donot discuss/provide hints to solution in the discussion forum, help your classmates learn themselves.
