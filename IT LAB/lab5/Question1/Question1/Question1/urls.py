
from django.contrib import admin
from django.urls import path, include
import Question

urlpatterns = [
    path('admin/', admin.site.urls),
    path('', include('Question.urls')),
]
