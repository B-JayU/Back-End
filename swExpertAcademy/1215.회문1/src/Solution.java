import java.util.Scanner;
import java.io.FileInputStream;

class Solution
{
	public static void main(String args[]) throws Exception
	{
		Scanner sc = new Scanner(System.in);
		
		char[][] ary = new char[8][8];
		int palinLength, countPalin;
		boolean check = false;
		String rowStr;
		for(int test_case = 1; test_case <= 10; test_case++)
		{
			palinLength = sc.nextInt();
			countPalin = 0;
			
			// Initialize wordBoard
			for (int i = 0; i < 8; i++) {
				rowStr = sc.next();
				for (int j = 0; j < 8; j++) {
					ary[i][j] = rowStr.charAt(j);
				}
			}
			
			for (int i = 0; i <8; i++) {
				for (int j = 0; j <8; j++) {
					
					// 가로 회문찾기
					check = true;
					
					if (j+palinLength-1<8) {
						for (int k = 0; k < palinLength/2; k++) {
							if (ary[i][j+k] != ary[i][j+palinLength-1-k]) {
								check = false;
								break;
							}
								
						}
						
						if(check == true)
							countPalin++;
					}
					
					// 세로 회문찾기
					check = true;
					
					if (i+palinLength-1<8) {
						for (int k = 0; k < palinLength/2; k++) {
							if (ary[i+k][j] != ary[i+palinLength-1-k][j]) {
								check = false;
								break;
							}
						}
						
						if (check==true)
							countPalin++;
					}
					
				}
			}
			
			System.out.println("#" + test_case + " " + countPalin);
		
		}
	}
}