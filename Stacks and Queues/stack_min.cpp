/*
    Question: how would you implement a stack min function that returns the minimum element in O(1) time?

    Solution: have a member variable "min" in the Stack class. Actually that doesn't work because if pop() deletes our min element, then it needs to update to the next smallest element
*/