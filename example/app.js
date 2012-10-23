// This is a test harness for your module
// You should do something interesting in this harness 
// to test out the module and to provide instructions 
// to users on how to use it by example.


// open a single window
var win = Ti.UI.createWindow({
	backgroundColor:'white'
});
var label = Ti.UI.createLabel();
win.add(label);
win.open();

// TODO: write your module tests here
var tisvprogresshud = require('com.qnyp.tisvprogresshub');
Ti.API.info("module is => " + tisvprogresshud);
Ti.API.debug(tisvprogresshud);

var progress = tisvprogresshud.createView();
win.add(progress);

var container = Ti.UI.createScrollView({
  width: Ti.UI.FILL,
  height: Ti.UI.FILL,
  layout: 'vertical'
});

// show status
win.add(container);
var button1 = Ti.UI.createButton({title:'show', width: Ti.UI.SIZE, height: Ti.UI.SIZE, top:10, bottom:10});
button1.addEventListener('click', function(){
  progress.show();
  setTimeout(function() {
    progress.dismiss();
  }, 2000);
  
});
container.add(button1);

var button2 = Ti.UI.createButton({title:'show with status', width: Ti.UI.SIZE, height: Ti.UI.SIZE, top:10, bottom:10});
button2.addEventListener('click', function(){
  progress.showWithStatus({status:'Loading...'});
  setTimeout(function() {
    progress.dismiss();
  }, 2000);

});
container.add(button2);

// show status with mask
var button3 = Ti.UI.createButton({title:'show with status and masktype black', width: Ti.UI.SIZE, height: Ti.UI.SIZE, top:10, bottom:10});
button3.addEventListener('click', function(){
  progress.showWithStatus({status:'Success!', maskType:'3'});
  setTimeout(function() {
    progress.dismiss();
  }, 2000);
});
container.add(button3);

var button4 = Ti.UI.createButton({title:'show with status and masktype gradient', width: Ti.UI.SIZE, height: Ti.UI.SIZE, top:10, bottom:10});
button4.addEventListener('click', function(){
  progress.showWithStatus({status:'Success!', maskType:'4'});
  setTimeout(function() {
    progress.dismiss();
  }, 2000);
});
container.add(button4);

// show success or error
var button31 = Ti.UI.createButton({title:'show success with status', width: Ti.UI.SIZE, height: Ti.UI.SIZE, top:10, bottom:10});
button31.addEventListener('click', function(){ progress.showSuccessWithStatus({status:'Success!'}); });
container.add(button31);

var button32 = Ti.UI.createButton({title:'show error with status', width: Ti.UI.SIZE, height: Ti.UI.SIZE, top:10, bottom:10});
button32.addEventListener('click', function(){ progress.showErrorWithStatus({status:'Error!'}); });
container.add(button32);

// dismiss
var button41 = Ti.UI.createButton({title:'dismiss', width: Ti.UI.SIZE, height: Ti.UI.SIZE, top:10, bottom:10});
button41.addEventListener('click', function(){ progress.dismiss(); });
container.add(button41);

var button42 = Ti.UI.createButton({title:'dismissWithSuccess', width: Ti.UI.SIZE, height: Ti.UI.SIZE, top:10, bottom:10});
button42.addEventListener('click', function(){ progress.dismissWithSuccess({status:'Success!'}); });
container.add(button42);

var button43 = Ti.UI.createButton({title:'dismissWithSuccess', width: Ti.UI.SIZE, height: Ti.UI.SIZE, top:10, bottom:10});
button43.addEventListener('click', function(){ progress.dismissWithError({status:'Error!'}); });
container.add(button43);
