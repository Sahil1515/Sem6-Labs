from django.shortcuts import render

def func(request):
    if request.method=='POST':
        data=request.POST
    context={
        'data':data
    }
    return render(request,'index.html',context=context)