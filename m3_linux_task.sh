wget -q -O - http://neva.today grep -o "http:.*" | grep -E -v "http://neva.today|http://neva.today" > nevatoday.txt

 -dump -listonly "class="main_one_news"" | grep -o "http:.*" | grep -E -v "http://neva.today|http://neva.today" > file.txt
 
 wget -q -O - class="main_one_news" grep -o "http:.*" | grep -E -v "http://neva.today|http://neva.today" > nevatoday.txt
