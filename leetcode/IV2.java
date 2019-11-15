package test;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;
import java.util.stream.Collectors;

class Pos {
	int x;
	int y;

	Pos(int x, int y) {
		this.x = x;
		this.y = y;
	}
}

public class IV2 {

	public static void main(String[] args) {

		int[][] arr1 = { 
				{ 1, 0, 0, 0, 0 }, 
				{ 0, 1, 0, 0, 0 }, 
				{ 0, 0, 1, 0, 0 }, 
				{ 0, 0, 0, 1, 0 },
				{ 0, 0, 0, 0, 1 }, 
		};

		List<List<Integer>> grid1 = new ArrayList<>();
		for (int i = 0; i < arr1.length; i++) {
			List<Integer> list = Arrays.stream(arr1[i]).boxed().collect(Collectors.toList());
			grid1.add(list);
		}

		int ret = method(arr1.length, arr1[0].length, grid1);
		System.out.println(ret);

		int[][] arr2 = { 
				{ 0, 0, 1, 0, 0, 0 }, 
				{ 0, 0, 0, 0, 0, 0 }, 
				{ 0, 0, 0, 0, 0, 1 }, 
				{ 0, 0, 0, 0, 0, 0 },
				{ 0, 1, 0, 0, 0, 0 }, 
		};

		List<List<Integer>> grid2 = new ArrayList<>();

		for (int i = 0; i < arr2.length; i++) {
			List<Integer> list = Arrays.stream(arr2[i]).boxed().collect(Collectors.toList());
			grid2.add(list);
		}

		ret = method(arr2.length, arr2[0].length, grid2);
		System.out.println(ret);

	}

	public static int method(int rows, int columns, List<List<Integer>> grid) {
		int ret = 0;
		int newx = 0;
		int newy = 0;
		Pos pos;

		int[] dx = { -1, 1, 0, 0 };
		int[] dy = { 0, 0, -1, 1 };

		Queue<Pos> q = new LinkedList<>();
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < columns; j++) {
				if (grid.get(i).get(j) == 1) {
					q.add(new Pos(i, j));
				}
			}
		}

		q.add(new Pos(-1, -1));
		ret++;

		while (q.size() != 0) {
			pos = q.poll();
			if (pos.x == -1) {

				if (q.isEmpty()) {
					break;

				}
				print(grid);
				q.add(new Pos(-1, -1));
				ret++;
				continue;
			}

			for (int i = 0; i < 4; i++) {
				newx = pos.x + dx[i];
				newy = pos.y + dy[i];
				if (newx >= 0 && newx < rows 
						&& newy >= 0 && newy < columns 
						&& grid.get(newx).get(newy) == 0) {
					grid.get(newx).set(newy, 1);
					q.add(new Pos(newx, newy));
				}
			}
		}

		return --ret;

	}

	static void print(List<List<Integer>> grid) {
		System.out.println("---------------");
		for (int i = 0; i < grid.size(); i++) {
			for (int j = 0; j < grid.get(0).size(); j++) {
				System.out.print(grid.get(i).get(j));
				System.out.print(",");
			}
			System.out.println("");
		}

	}

}
