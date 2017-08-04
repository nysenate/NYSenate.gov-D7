(function($) {
// implementation of imce.hookOpValidate.
imce.rotateOpValidate = function() {
  if (!imce.validateImage()) {
  return false};
  return true;
};
//implementation of imce.hookOpSubmit
imce.rotateOpSubmit = function(fop) {
 if (imce.fopValidate(fop)) {
    imce.fopLoading(fop, true);
     $.ajax($.extend(imce.fopSettings(fop), {success: imce.rotateResponse}));
  }
};

// Fix browser cache showing the non-rotated image because filename does not change
// We also force all other files to bypass the cache, but only on first load
// This is to prevent cached images being displayed when a user re-loads IMCE EG: comes back to make more changes
imce.rotateFids = {};
imce.rotateNums = {};
imce.fileNums = {};

imce.rotateGetURL = imce.getURL;
imce.getURL = function (fid) {
  var url = imce.rotateGetURL(fid);
  // To prevent browsers from caching altered images, on first load we bypass the browser cache
  var fileRand = imce.fileNums[fid] ? imce.fileNums[fid] : Math.floor((Math.random() * 1000) + 1);
  imce.fileNums[fid] = fileRand;
  // If this is a rotated image we use its random URL.
  fileRand = imce.rotateFids[fid] ? imce.rotateFids[fid] : fileRand;
  // Add suffix to prevent caching.
  return url + '?' + fileRand;
};

// Custom response to keep track of overwritten files.
imce.rotateResponse = function(response) {
if(!imce.el('edit-rotate-copy').checked){

  // Record rotated images
  var random_value = 0;
  var random_loop = 0;
  var row, w, h;
  for (var fid in imce.selected) {

    // Generate a random number between 1 and 1000 and check it has not been used before.
    // It is possible that this could cause a continues loop so we limit the number of checks.
    random_loop = 0;
    while (random_value == 0) {
      // Generate number
      random_value = Math.floor((Math.random() * 1000) + 1);
      // Check if it has been used before
      if (typeof imce.rotateNums[random_value] == 'undefined') {
        imce.rotateNums[random_value] = random_value;
        break;
      }
      // Stop after 10 tries
      random_loop++;
      if (random_loop >= 10) {
        random_value = random_value * 2;
        break;
      }
      // Try again
      random_value = 0;
    }

    imce.rotateFids[fid] = random_value;

    // Swap width and height because it has been rotated
    if (row = imce.fids[fid]) {
    if(!imce.el('edit-rotate-direction-flip').checked){
      h = row.cells[2].innerHTML;
      w = row.cells[3].innerHTML;
      row.cells[2].innerHTML = w;
      row.cells[3].innerHTML = h;
      }
    }
  }
}
  // Re-set preview
  imce.setPreview(imce.selcount == 1 ? imce.lastFid() : null);

  imce.processResponse(response);
};

})(jQuery);
