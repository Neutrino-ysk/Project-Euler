Option Explicit

Const vbMaximizedFocus = 3

Dim overview, boxtitle, template, problemNumber, title, projectPath

projectPath = "C:\Users\coop\Documents\project euler Git\Project-euler\"

overview = "[機能]" & vbCr  &  "Project-eulerの問題フォルダを自動生成します。" & vbCr & vbCr & "※入力内容" & vbCr & "作成したいフォルダの問題番号を入力してください。"
boxtitle = "FolderMaker_Project-euler（問題番号入力）"
template = "問題番号"

problemNumber = InputBox(overview, boxtitle, template)

If IsEmpty(problemNumber) Or IsNumeric(problemNumber) <> true Then
    MsgBox "問題番号を入力してください"
ElseIf IsNumeric(problemNumber) = true then

    overview = "※入力内容" & vbCr  &  "作成したいフォルダの題名を入力してください。"
    boxtitle = "FolderMaker_Project-euler（題名入力）"
    template = "題名"

    title = InputBox(overview, boxtitle, template)

    If IsEmpty(title) Then
        MsgBox "題名を入力してください"
    Else
        call makeFolder(problemNumber, title)
        call makeFile(problemNumber, title)
        call makeScreenshot()
    End If
End If

Sub makeFolder(problemNumber, title)
    Dim objFSO, strFolder, strMessage

    Set objFSO = WScript.CreateObject("Scripting.FileSystemObject")  
    '作成するフォルダ名
    strFolder = projectPath & "problem" & problemNumber & "-" & title
    If objFSO.FolderExists(strFolder) = True Then
        '同名のフォルダがあるか
        strMessage = strFolder + "は既に存在しています。"
    else
        'フォルダの作成
        objFSO.CreateFolder(strFolder)
        'フォルダ作成の処理で、エラーが発生していないか
        if Err.Number = 0 Then
            strMessage = strFolder & "を作成しました。"
        else
            strMessage = "エラー：" & Err.Description
        end if
    end if
    MsgBox(strMessage)
End Sub

Sub makeFile(problemNumber, title)
    Dim objFSO, tso, strFolder, strFile

    strFolder = projectPath & "problem" & problemNumber & "-" & title & "\"
    strFile = "problem" & problemNumber & ".c"
    Set objFSO = CreateObject("Scripting.FileSystemObject")
    Set tso = objFSO.CreateTextFile(strFolder & strFile)
    tso.Write("#include <stdio.h>")
    tso.WriteBlankLines(2)
    tso.WriteLine("int main(void)" + vbCrLf + "{")
    tso.WriteBlankLines(1)
    tso.Write("    return 0;" + vbCrLf + "}")
    tso.Close
End Sub

Sub makeScreenshot()
    Dim objWShell
    Set objWShell = CreateObject("WScript.Shell")
    objWShell.Run "C:\WINDOWS\system32\SnippingTool.exe", vbMaximizedFocus, False
    Set objWShell = Nothing
End Sub