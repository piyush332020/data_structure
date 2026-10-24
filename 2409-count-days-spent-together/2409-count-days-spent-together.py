
class Solution:
    def countDaysTogether(self, arriveAlice: str, leaveAlice: str, arriveBob: str, leaveBob: str) -> int:
        arr = [31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]

        def convert(date):
            month, day = map(int, date.split("-"))
            total = day

            for i in range(month - 1):
                total += arr[i]

            return total

        startAlice = convert(arriveAlice)
        endAlice = convert(leaveAlice)
        startBob = convert(arriveBob)
        endBob = convert(leaveBob)

        start = max(startAlice, startBob)
        end = min(endAlice, endBob)

        return max(0, end - start + 1)
