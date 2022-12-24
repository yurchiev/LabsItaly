import java.util.Random;

public class HashTable {
    private static final int TABLE_SIZE = 30;
    private static final int BIRTH_YEAR = 1995;
    private static final int BIRTH_MONTH = 4;
    private String[] table;
    private int numCollisions;

    public HashTable() {
        table = new String[TABLE_SIZE];
        numCollisions = 0;
    }

    // Hash function to calculate the hash value of a word
    private int hash(String word) {
        return Math.abs(BIRTH_YEAR % BIRTH_MONTH - word.length()) % TABLE_SIZE;
    }

    // Insert a word into the hash table
    public void insert(String word) {
        int hashValue = hash(word);
        int index = hashValue;
        while (table[index] != null) {
            // Linear probing to find an empty slot
            index = (index + 1) % TABLE_SIZE;
            numCollisions++;
        }
        table[index] = word;
    }

    // Print all the elements in the hash table
    public void print() {
        for (int i = 0; i < TABLE_SIZE; i++) {
            if (table[i] != null) {
                System.out.println(i + ": " + table[i]);
            }
        }
    }

    // Calculate the number of collisions in the hash table
    public int getNumCollisions() {
        return numCollisions;
    }
}
