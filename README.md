<div>
    <h2>Name: Sagar Mandal</h2>
    <h2>Roll no.: 60 (A4)</h2>
    <h2>Teacher Assessment</h2>
</div>
<hr>
<div>
    <h2><u>Question Statement:</u></h2>
    <p>
        Consider two strings A = “qpqrr” and B = “pqprqrp”. Let x be the length of the longest common subsequence (not necessarily contiguous) between A and B and let y be the number of such longest common subsequence between A and B. Then what is the value of x + 5y?
    </p>
</div>
<hr>
<div>
    <h2><u>Approach:</u></h2>
    <div>
        <strong>
            The following steps are followed for finding the longest common subsequence.
        </strong>
    </div>
    <ol>
        <li>
            Create a table of dimension n+1*m+1 where n and m are the lengths of A and B respectively. The first row and the first column are filled with zeros.    
        </li>
        <li>
            Fill each cell of the table using the following logic.
            <ul>
                <li>
                    If the character correspoding to the current row and current column are matching, then fill the current cell by adding one to the diagonal element.
                </li>
                <li>
                    Else take the maximum value from the previous column and previous row element for filling the current cell.
                </li>
            </ul>
        </li>
        <li>
            <strong>Step 2</strong> is repeated until the table is filled.
        </li>
        <li>
            The value in the last row and the last column is the length of the longest common subsequence.
        </li>
    </ol>
    <div>
        <strong>
          The following steps are followed to find total number of possible longest common subsequence.
        </strong>
    </div>
    <ol>
        <li>
            Create a vector V to store all possible longest common subsequence.
        </li>
        <li>
            Traverse both A and B strings and return a value based on the following conditions.
            <ul>
                <li>
                    Return an empty string if the end of either sequence is reached.
                </li>
                <li>
                    If the last character of A and B matches, append the last characters of A and B in the vector and find all LCS of the substrings A[0...n-2] and B[0...m-2].
                </li>
                <li>
                    When the last character of A and B don't match, if the top cell of the current cell has more value than the left cell, then ignore the current character of string A and find all LCS of substring A[0…n-2], B[0…m-1]. Else, find all LCS of the substrings A[0...n-1], B[0...m-2].
                </li>
            </ul>
        </li>
        <li>
            If the top cell has the same value as the left cell, then consider both characters.<br>
            <em>
                vector&lt;string&gt; top = LCS(A, B, m - 1, n, lcstable);<br>
                vector&lt;string&gt; left = LCS(A, B, m, n - 1, lcstable);
            </em>
        </li>
        <li>
            Merge two vectors and return the vector.
        </li>
        <li>
            Convert the vector V into a set to get unique values for the longest common subsequence and return the size of the set.
        </li>
    </ol>
</div>
<hr>
<div>
    <h2><u>Test Cases:</u></h2>
    <div>
        <h3>Test Case 1</h3>
        <p>A = <em>"qpqrr"</em>, B = <em>"pqprqrp"</em></p>
        <p>All possible longest common subsequence - <em>“qprr”</em>, <em>“pqrr”</em> and <em>“qpqr”</em></p>
        <p>X = 4 and Y = 3</p>
        <p>X + 5Y = 19</p>
        <img src="https://user-images.githubusercontent.com/115873710/204143827-b18ca681-2ae4-42f6-9978-d7e2bbb6c574.png" alt="test-case-1" />
    </div>
    <div>
        <h3>Test Case 2</h3>
        <p>A = <em>"abcbdaba"</em>, B = <em>"bdcabaa"</em></p>
        <p>All possible longest common subsequence - <em>“bcaba”</em>, <em>“bcbaa”</em> and <em>“bdaba”</em></p>
        <p>X = 5 and Y = 3</p>
        <p>X + 5Y = 20</p>
        <img src="https://user-images.githubusercontent.com/115873710/204143897-a7154719-9a51-42c2-8769-dac0b253cc5b.png" alt="test-case-2" />
    </div>
    <div>
        <h3>Test Case 3</h3>
        <p>A = <em>"abcdgh"</em>, B = <em>"aedfhr"</em></p>
        <p>All possible longest common subsequence - <em>“adh”</em></p>
        <p>X = 3 and Y = 1</p>
        <p>X + 5Y = 8</p>
        <img src="https://user-images.githubusercontent.com/115873710/204144051-12047c51-9262-459f-9553-76db72cac186.png" alt="test-case-3" />
    </div>
</div>
