/*127. Word Ladder*/

/*
A transformation sequence from word beginWord to word endWord using a dictionary wordList is a sequence of words beginWord -> s1 -> s2 -> ... -> sk such that:

Every adjacent pair of words differs by a single letter.
Every si for 1 <= i <= k is in wordList. Note that beginWord does not need to be in wordList.
sk == endWord
Given two words, beginWord and endWord, and a dictionary wordList, return the number of words in the shortest transformation sequence from beginWord to endWord, or 0 if no such sequence exists.

Example 1:
Input: beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log","cog"]
Output: 5
Explanation: One shortest transformation sequence is "hit" -> "hot" -> "dot" -> "dog" -> cog", which is 5 words long.

Example 2:
Input: beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log"]
Output: 0
Explanation: The endWord "cog" is not in wordList, therefore there is no valid transformation sequence.
 

Constraints:
1 <= beginWord.length <= 10
endWord.length == beginWord.length
1 <= wordList.length <= 5000
wordList[i].length == beginWord.length
beginWord, endWord, and wordList[i] consist of lowercase English letters.
beginWord != endWord
All the words in wordList are unique.
*/
import java.util.*;
class Word{
    String w;
    int step;
    public Word(String s,int st){
        this.w=s;
        this.step=st;
    }
}
class Solution {
    public int ladderLength(String beginWord, String endWord, List<String> wordList) {
        if(!wordList.contains(endWord)){
            return 0;
        } 
        Map<String,Integer> m=new HashMap<>();
        for(String w:wordList){
            m.put(w,1);
        }
        Queue<Word> q=new LinkedList<>();
        q.add(new Word(beginWord,1));
        while(!q.isEmpty()){
            Word curr=q.poll();
            if(curr.w.equals(endWord)){
                return curr.step;
            }
            for(int i=0;i<curr.w.length();i++){
                char w[]=curr.w.toCharArray();
                for(char ch='a';ch<='z';ch++){
                    if(ch==w[i]){
                        continue;
                    }
                    w[i]=ch;
                    String newstr=new String(w);
                    if(m.containsKey(newstr)){
                        q.add(new Word(newstr,curr.step+1));
                        m.remove(newstr);
                    }
                }
            }
        }
        return 0;
    }
}
public class Q0127{
     public static void main(String[] args){
        Scanner sc=new Scanner(System.in);
        String beginString=sc.nextLine();
        String endString=sc.nextLine();
        List<String> wordList=new ArrayList<>();
        int n=sc.nextInt();
        sc.nextLine();
        for(int i=0;i<n;i++){
            wordList.add(sc.nextLine());
        }
        Solution s=new Solution();
        System.out.print(s.ladderLength(beginString,endString,wordList));
        sc.close();
     }
}