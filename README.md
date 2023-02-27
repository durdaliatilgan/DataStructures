# DataStructures
> AVL Tree
Binary Search Tree
Balanced Tree
Radix Sort
Queue Structure
Linked List

Program çalıştığı gibi Veri.txt dosyasını okur. Veri.txt dosyasından okunan her satırda sayılar 
boşluklar ile ayrılmıştır. Her satırda tek sayı adedince sayılar bulunmaktadır. Satırdaki her sayı bir 
hücreyi temsil etmekte ve sayısal değer de hücrenin DNA uzunluğunu ifade etmektedir. Hücreler bir 
araya gelerek dokuyu oluşturmaktadır. Yani dosyadaki her satır bir dokudur. 20 adet doku bir araya 
gelerek organı oluşturur. Her satırdaki sayılar Radix Sort ile küçükten büyüğe sıralanıp 
sıralamada ortada kalan sayıya göre organda bulunan ve dokuları tutan Bağıl ikili arama ağacına
yerleştirilir. ikili arama ağacı doku nesnelerinden oluşmaktadır. İkili arama ağaçlarında eşit olma 
durumunda sola ekleme yapılmıştır. Yine 100 adet organ bir araya gelerek sistemi oluşturmaktadır. 
Sistemlerde bir araya gelerek organizmayı oluşturur. Sistem sayısında herhangi bir kısıtlama 
yoktur. Bu mantık ile dosya okunup organizma ekrana yazdırılır. Ekranda her satır bir sistemi 
temsil etmektedir. Ekrana satır yani bir sistem yazdırılırken sistemi oluşturan organlarda bulunan ikili 
arama ağacı AVL ağacı mantığına göre dengeli ise boşluk karakteri, dengesiz ise # karakteri ekrana 
yazdırılmaktadır.

![resim](https://github.com/durdaliatilgan/DataStructures/blob/master/img/Capture3.PNG)

Organizma ekranda göründükten sonra enter tuşuna basıldığında ağaçların kökünde bulunan orta 
hücre DNA uzunluğu 50'ye tam bölünüyorsa bu organı oluşturan dokuların hücreleri aşağıdaki kurala 
göre mutasyona uğrar.

• Hücrenin DNA uzunluk değeri çift olanlar mutasyona uğrayıp değer yarıya düşürülür.
• Çift olmayanlar mutasyona uğramaz.

Ağaçların kökünde bulunan orta hücre DNA uzunluğu 50'ye tam bölünemiyorsa bu organı oluşturan 
dokuların hücreleri mutasyona uğramaz.
Sadece mutasyona uğrayan ikili arama ağacı post order olarak bir diziye alınıp ağaç dosyadan okuma 
mantığına göre yeniden oluşturulur. Diğer ağaçlar aynı şekilde kalır. Bu mantıkla oluşan 
yeni organizma tekrar ekrana yazdırılır. Yukarıdaki örnek mutasyona uğradığında aşağıdaki gibi 
organizma çıktısı alınmıştır.

![resim](https://github.com/durdaliatilgan/DataStructures/blob/master/img/Capture4.PNG)


Bu proje Veri Yapıları dersi projesi kapsamında geliştirilmiştir.


ENG:

DataStructures

AVL Tree Binary Search Tree Balanced Tree Radix Sort Queue Structure Linked List

The program reads the Veri.txt file as it runs. Each line in the Veri.txt file contains numbers separated by spaces. Each line contains as many numbers as there are cells. Each number in the line represents the length of a DNA strand in a cell. Cells come together to form tissue, so each line represents a tissue. 20 tissues come together to form an organ. The numbers in each line are sorted in ascending order using Radix Sort, and the binary search tree is created using the middle number in the sorted list as the root. The binary search tree consists of tissue objects. If there are equal values in the binary search tree, the new node is inserted to the left. Finally, 100 organs come together to form a system, and the system is a part of the organism. There is no restriction on the number of systems. The program reads the file and prints the organism to the screen. Each line on the screen represents a system. When a line, or a system, is printed to the screen, if the binary search tree of the organs in the system is balanced according to the AVL tree logic, a blank space character is printed. If it is unbalanced, a # character is printed.

![resim](https://github.com/durdaliatilgan/DataStructures/blob/master/img/Capture3.PNG)

After the organism is displayed on the screen, if the middle cell of the binary search tree in an organ has a DNA length that is divisible by 50, the cells of the tissues that make up that organ undergo mutation according to the following rule:

• Cells with an even DNA length are mutated and their length is halved. • Cells with an odd DNA length are not mutated.

If the DNA length of the middle cell of the binary search tree in an organ is not divisible by 50, the cells of the tissues that make up that organ are not mutated. Only the binary search tree that undergoes mutation is converted into an array in postorder, and then it is reconstructed using the file reading logic. The other trees remain the same. The new organism created in this way is printed to the screen again. The example above shows the organism after the mutation has taken place.

![resim](https://github.com/durdaliatilgan/DataStructures/blob/master/img/Capture4.PNG)

This project was developed as a part of the Data Structures course.
