# DataStructures

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
