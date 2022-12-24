import java.util.Random;

public class Main {
    public static void main(String[] args) {
        HashTable hashTable = new HashTable();

        // Insert 25 random words into the hash table
        Random random = new Random();
        for (int i = 0; i < 25; i++) {
            int wordLength = random.nextInt(10) + 1;
            String word = "";
            for (int j = 0; j < wordLength; j++) {
                char c = (char)(random.nextInt(26) + 'a');
                word += c;
            }
            hashTable.insert(word);
        }

        // Print all the elements in the hash table
        hashTable.print();

        // Print the number of collisions in the hash table
        System.out.println("Number of collisions: " + hashTable.getNumCollisions());
    }
}
