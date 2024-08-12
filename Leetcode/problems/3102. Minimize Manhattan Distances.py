#https://leetcode.com/problems/minimize-manhattan-distances/description/
#Difficulty: hard
sub = lambda x: x[0]-x[1]

class Solution:
    def minimumDistance(self, points: List[List[int]]) -> int:

        def maxDist(pts: List)-> int:

            sums, difs= list(map(sum,pts)), list(map(sub,pts))
            print(sums)#,difs)

            return max(max(sums) - min(sums), 
                       max(difs) - min(difs))

        lDiag, rDiag = sorted(points, key = sub), sorted(points, key = sum)

        return min(maxDist(lDiag[  :-1]),
                   maxDist(lDiag[ 1:  ]),
                   maxDist(rDiag[  :-1]),
                   maxDist(rDiag[ 1:  ]))