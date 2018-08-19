import java.io.*;
import java.util.Map;
import java.util.concurrent.ConcurrentHashMap;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
import java.util.concurrent.TimeUnit;
import java.util.concurrent.atomic.AtomicLong;

public class WordCount {
    private Map<String, AtomicLong> map = new ConcurrentHashMap<>();

    class Count implements Runnable {
        private String lineStr;

        public Count(String str) {
            lineStr = str;
        }

        @Override
        public void run() {
            String[] words = lineStr.split("[^a-zA-Z0-9]+");
            for (String word : words) {
                AtomicLong counter = map.get(word);
                if (counter == null) {
                    AtomicLong nNum = new AtomicLong(0);
                    counter = map.putIfAbsent(word, nNum);
                    if (counter == null)
                        counter = nNum;
                }
                counter.incrementAndGet();
            }
        }
    }

    public static void main(String[] args) {
        WordCount o = new WordCount();
        int proNum = Runtime.getRuntime().availableProcessors();
        File file = new File("./text.txt");
        BufferedReader reader;
        try {
            String line;
            reader = new BufferedReader(new FileReader(file));
            ExecutorService executor = Executors.newFixedThreadPool(proNum);
            while ((line = reader.readLine()) != null) {
                Runnable t = o.new Count(line);
                executor.execute(t);
            }
            executor.shutdown();
            while (!executor.awaitTermination(10, TimeUnit.SECONDS));
            System.out.println(o.map);
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        } catch (IOException e) {
            e.printStackTrace();
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
    }
}
