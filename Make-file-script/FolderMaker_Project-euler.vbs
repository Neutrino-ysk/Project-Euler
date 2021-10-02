Option Explicit

Const vbMaximizedFocus = 3

Dim overview, boxtitle, template, problemNumber, title, projectPath

projectPath = "C:\Users\coop\Documents\project euler Git\Project-euler\"

overview = "[�@�\]" & vbCr  &  "Project-euler�̖��t�H���_�������������܂��B" & vbCr & vbCr & "�����͓��e" & vbCr & "�쐬�������t�H���_�̖��ԍ�����͂��Ă��������B"
boxtitle = "FolderMaker_Project-euler�i���ԍ����́j"
template = "���ԍ�"

problemNumber = InputBox(overview, boxtitle, template)

If IsEmpty(problemNumber) Or IsNumeric(problemNumber) <> true Then
    MsgBox "���ԍ�����͂��Ă�������"
ElseIf IsNumeric(problemNumber) = true then

    overview = "�����͓��e" & vbCr  &  "�쐬�������t�H���_�̑薼����͂��Ă��������B"
    boxtitle = "FolderMaker_Project-euler�i�薼���́j"
    template = "�薼"

    title = InputBox(overview, boxtitle, template)

    If IsEmpty(title) Then
        MsgBox "�薼����͂��Ă�������"
    Else
        call makeFolder(problemNumber, title)
        call makeFile(problemNumber, title)
        call makeScreenshot()
    End If
End If

Sub makeFolder(problemNumber, title)
    Dim objFSO, strFolder, strMessage

    Set objFSO = WScript.CreateObject("Scripting.FileSystemObject")  
    '�쐬����t�H���_��
    strFolder = projectPath & "problem" & problemNumber & "-" & title
    If objFSO.FolderExists(strFolder) = True Then
        '�����̃t�H���_�����邩
        strMessage = strFolder + "�͊��ɑ��݂��Ă��܂��B"
    else
        '�t�H���_�̍쐬
        objFSO.CreateFolder(strFolder)
        '�t�H���_�쐬�̏����ŁA�G���[���������Ă��Ȃ���
        if Err.Number = 0 Then
            strMessage = strFolder & "���쐬���܂����B"
        else
            strMessage = "�G���[�F" & Err.Description
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