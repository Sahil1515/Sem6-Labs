from django.shortcuts import render

# Create your views here.


from django.http import HttpResponse

def index(request):

    array = [ "emp" + str(i) for i in range(15)]
    context={'mylist': array}
    return render(request,'index.html',context=context)