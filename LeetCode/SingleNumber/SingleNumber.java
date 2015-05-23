package Summon;

import java.util.HashMap;
import java.util.HashSet;

public class SingleNumber {

	public static int singleNumber1(int[] nums) {
		int sn = 0;
		for (int i : nums) {
			sn ^= i;
		}
		return sn;
	}
	
	public static int singleNumber2(int[] nums) {
		HashSet<Integer> set = new HashSet<Integer>();
		for (int i : nums) {
			if (set.contains(i)) {
				set.remove(i);
			} else {
				set.add(i);
			}
		}
		return set.iterator().next();
	}
	
	public static int singleNumber3(int[] nums) {
		HashMap<Integer, Integer> map = new HashMap<Integer, Integer>();
		for (int i : nums) {
			if (map.containsKey(i)) {
				map.remove(i);
			} else {
				map.put(i, 1);
			}
		}
		for (int i : nums) {
			if (map.containsKey(i)) {
				return i;
			}
		}
		return -1;
	}
	
	public static void main(String[] argc) {
		int[] nums = {3, 9, 2, 7, 8, 6, 0, 9, 3, 2, 6, 7, 8, 5, 0};
		int sn = singleNumber1(nums);
		System.out.println("method 1: " + sn);
		sn = singleNumber2(nums);
		System.out.println("method 2: " + sn);
		sn = singleNumber2(nums);
		System.out.println("method 3: " + sn);
	}
}
