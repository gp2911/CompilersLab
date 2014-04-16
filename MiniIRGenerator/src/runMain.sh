clear
clear
clear
javac *.java myClasses/*.java
java Main < $1 > test.miniIR
java -jar ../../../Tools/pgi.jar < test.miniIR
